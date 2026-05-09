#include "loggerCpp/logEventRouter.hpp"
#include "loggerCpp/logSink.hpp"

void LogEventRouter::setLogLevel(utils::LogLevel level) noexcept {
    std::unique_lock lock(routeMutex);
    currentLogLevel = level;
}

void LogEventRouter::addRoute(utils::LogLevel level, std::shared_ptr<LogSink> sink) noexcept {
    std::unique_lock lock(routeMutex);
    routes[level].push_back(std::move(sink));
}

void LogEventRouter::routeEvent(const utils::LogEvent& event) noexcept {
    std::shared_lock lock(routeMutex);
    if (event.level >= currentLogLevel) [[likely]] {
        auto it = routes.find(event.level);
        if (it != routes.end()) [[likely]] {
            for (const auto& sink : it->second) {
                sink->write(event);
            }
        }
    }
}