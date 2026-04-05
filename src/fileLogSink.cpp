#include "loggerCpp/fileLogSink.hpp"
#include <format>
#include <iostream>

FileLogSink::FileLogSink(std::string_view name)
    : fileName(std::string(name), std::ios::app)
{
    if (!fileName.is_open()) {
        throw std::runtime_error(std::format("Failed to open log file: {}", name));
    }
}

void FileLogSink::write(const utils::LogEvent& event) {
    if (!fileName.is_open()) {
        std::cerr << "FileLogSink: log file is not open\n";
        return;
    }

    fileName << std::format("[{}] [{}] ({}:{}) {}\n",
        event.timestamp,
        utils::getLogLevelString(event.level),
        event.location.file_name(),
        event.location.line(),
        event.message);

    fileName.flush();
}
