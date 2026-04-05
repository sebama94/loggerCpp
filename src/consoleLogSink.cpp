#include "loggerCpp/consoleLogSink.hpp"
#include <format>
#include <iostream>

void ConsoleLogSink::write(const utils::LogEvent& event) {
    // ERROR and CRITICAL go to stderr; everything else to stdout.
    auto& out = (event.level >= utils::LogLevel::ERROR) ? std::cerr : std::cout;

    out << std::format("{}[{}]{} [{}] ({}:{}) {}\n",
        utils::getColorForLogLevel(event.level),
        utils::getLogLevelString(event.level),
        COLOR_RESET,
        event.timestamp,
        event.location.function_name(),
        event.location.line(),
        event.message);

    out.flush();
}
