// LoggingEngine.cpp

#include "loggerCpp/loggingEngine.hpp"
#include <memory>
#include <latch>
#include <semaphore>


LoggingEngine& LoggingEngine::getInstance() noexcept {
    static LoggingEngine instance;
    return instance;
}

LoggingEngine::LoggingEngine() : asyncMode(false), stopLogging(false)
{
    globalLogLevel.store(utils::LogLevel::INFO, std::memory_order_relaxed);
    startAsync();
}

LoggingEngine::~LoggingEngine() noexcept {
    stopAsync();  // Ensure async logging thread stops on destruction
}

void LoggingEngine::setLogLevel(utils::LogLevel level) noexcept {
    std::lock_guard lock(sinkMutex);
    globalLogLevel.store(level, std::memory_order_relaxed);
    router.setLogLevel(level);
}

void LoggingEngine::addSink(std::shared_ptr<LogSink> sink, utils::LogLevel level) {
    if (!sink) return;
    std::lock_guard lock(sinkMutex);
    sinks.emplace_back(sink, level);
    router.addRoute(level, std::move(sink));
}

void LoggingEngine::processEvent(const utils::LogEvent& event) noexcept {
    if (event.level < globalLogLevel.load(std::memory_order_relaxed)) [[unlikely]] return;

    if (asyncMode) {
        std::lock_guard lock(queueMutex);
        eventQueue.push(event);
        queueCV.notify_one();
    } else {
        router.routeEvent(event);
    }
}

void LoggingEngine::startAsync() noexcept {
    std::lock_guard lock(queueMutex);
    if (!asyncMode) {
        asyncMode = true;
        stopLogging = false;
        loggingThread = std::jthread([this](std::stop_token stoken) {
            processEventQueue();
        });
    }
}

void LoggingEngine::stopAsync() noexcept {
    {
        std::lock_guard lock(queueMutex);
        if (!asyncMode) return;
        stopLogging = true;
        queueCV.notify_one();
    }
    if (loggingThread.joinable()) {
        loggingThread.join();
    }
    asyncMode = false;
}

void LoggingEngine::processEventQueue() noexcept {
    while (true) {
        std::unique_lock lock(queueMutex);
        queueCV.wait(lock, [this]() { return !eventQueue.empty() || stopLogging; });

        if (stopLogging && eventQueue.empty()) [[unlikely]] break;

        while (!eventQueue.empty()) {
            auto event = std::move(eventQueue.front());
            eventQueue.pop();

            lock.unlock();
            router.routeEvent(event);
            lock.lock();
        }
    }
}