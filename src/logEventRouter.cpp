#include "loggerCpp/logEventRouter.hpp"
#include "loggerCpp/logSink.hpp"

void LogEventRouter::setLogLevel(utils::LogLevel level) noexcept {
    currentLogLevel = level;
}

void LogEventRouter::addRoute(utils::LogLevel level, std::shared_ptr<LogSink> sink) noexcept {
    routes[level].push_back(std::move(sink));
}

void LogEventRouter::routeEvent(const utils::LogEvent& event) noexcept {
    if (event.level < currentLogLevel) return;

    // Deliver to every sink whose registered minimum level is <= event level.
    // A sink added at DEBUG receives DEBUG, INFO, WARNING, ERROR, CRITICAL.
    // A sink added at WARNING receives only WARNING, ERROR, CRITICAL.
    for (auto& [minLevel, sinks] : routes) {
        if (event.level >= minLevel) {
            for (const auto& sink : sinks) {
                sink->write(event);
            }
        }
    }
}
