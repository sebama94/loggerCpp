#pragma once

#include "logSink.hpp"

#include <string_view>
#include <fstream>

/**
 * @brief File output sink for logging with immediate writes
 *
 * This class implements a logging sink that writes log messages to a file.
 * Each write is flushed immediately to ensure no messages are lost on crash.
 */
class FileLogSink final : public LogSink {
public:
    /**
     * @brief Constructs a FileLogSink with the specified file name
     * 
     * @param fileName The name/path of the file to write logs to
     */
    explicit FileLogSink(std::string_view fileName);

    /**
     * @brief Writes a log event to the file
     * 
     * @param event The log event containing the message and metadata to be written
     * @throws std::runtime_error if file write fails
     * 
     * This function formats and writes the provided log event to the configured file
     * using buffered writes for better performance.
     */
    void write(const utils::LogEvent& event) override;

private:
    alignas(64) std::ofstream fileName; /**< Output file stream with cache line alignment */
};