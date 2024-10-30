
#include "loggerCpp/dataBaseLogSink.hpp"

void DataBaseLogSink::write(const utils::LogEvent& event) {
    // TODO: Implement database logging
    // This would connect to a database and insert log records
    std::cerr << "Error: Database logging not implemented\n";
    throw std::runtime_error("Database logging not implemented");
}

DataBaseLogSink::DataBaseLogSink(const std::string_view& database) {
    // TODO: Implement database logging
    // This would connect to a database and insert log records
    std::cerr << "Error: Database logging not implemented\n";
    throw std::runtime_error("Database logging not implemented");
}