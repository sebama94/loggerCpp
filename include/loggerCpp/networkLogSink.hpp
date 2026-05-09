#pragma once

#include "logSink.hpp"
#include <string>

/**
 * @brief Network output sink for logging (stub — not yet implemented)
 *
 * This class implements a logging sink that writes log messages to a network destination.
 * It inherits from the LogSink base class and provides network-specific logging functionality.
 */
class NetworkLogSink final : public LogSink {
public:
    /**
     * @brief Constructor with destination URL
     *
     * @param url The remote endpoint to send log messages to
     */
    explicit NetworkLogSink(std::string_view url);

    /**
     * @brief Writes a log event to the network destination
     *
     * @param event The log event containing the message and metadata to be written
     */
    void write(const utils::LogEvent& event) override;

private:
    std::string url_;
};