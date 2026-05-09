#include "loggerCpp/dataBaseLogSink.hpp"
#include <iostream>

DataBaseLogSink::DataBaseLogSink(std::string_view database) : database_(database) {}

void DataBaseLogSink::write(const utils::LogEvent& event) {
    // TODO: implement actual database insertion (SQLite, PostgreSQL, etc.)
    (void)event;
    std::cerr << "Warning: DataBaseLogSink not yet implemented (target: " << database_ << ")\n";
}