#pragma once

#include "logSink.hpp"
#include <string>

/**
 * @brief Database output sink for logging (stub — not yet implemented)
 *
 * This class implements a logging sink that writes log messages to a database.
 * It inherits from the LogSink base class and provides database-specific logging functionality.
 */
class DataBaseLogSink final : public LogSink {
public:
    /**
     * @brief Constructor with database connection string
     *
     * @param database Connection string or database name
     */
    explicit DataBaseLogSink(std::string_view database);

    /**
     * @brief Writes a log event to the database
     *
     * @param event The log event containing the message and metadata to be written
     */
    void write(const utils::LogEvent& event) override;

private:
    std::string database_;
};