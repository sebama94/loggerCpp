#include "loggerCpp/configurationManager.hpp"
#include "loggerCpp/consoleLogSink.hpp"
#include "loggerCpp/fileLogSink.hpp"
#include "loggerCpp/dataBaseLogSink.hpp"
#include "loggerCpp/networkLogSink.hpp"
#ifdef __unix__
#include "loggerCpp/sysLogSink.hpp"
#endif

#include <fstream>
#include <vector>

ConfigurationManager::ConfigurationManager() {
    LoggingEngine& logger = LoggingEngine::getInstance();
    #ifdef NDEBUG
        logger.setLogLevel(utils::LogLevel::INFO);
    #else
        logger.setLogLevel(utils::LogLevel::DEBUG);
    #endif
}

ConfigurationManager::ConfigurationManager(const utils::LogLevel& logLevel) {
    LoggingEngine& logger = LoggingEngine::getInstance();
    logger.setLogLevel(logLevel);
}

// --- Console sink ---

void ConfigurationManager::applyConsoleSink(const utils::LogLevel& level) {
    auto sink = std::make_shared<ConsoleLogSink>();
    LoggingEngine::getInstance().addSink(sink, level);
}

void ConfigurationManager::applyConsoleSink(const utils::LogLevel& level1, const utils::LogLevel& level2) {
    auto sink = std::make_shared<ConsoleLogSink>();
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
}

void ConfigurationManager::applyConsoleSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3) {
    auto sink = std::make_shared<ConsoleLogSink>();
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
}

void ConfigurationManager::applyConsoleSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4) {
    auto sink = std::make_shared<ConsoleLogSink>();
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
}

void ConfigurationManager::applyConsoleSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const utils::LogLevel& level5) {
    auto sink = std::make_shared<ConsoleLogSink>();
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
    logger.addSink(sink, level5);
}

// --- File sink ---

void ConfigurationManager::applyFileSink(const utils::LogLevel& level, const std::string_view& filename) {
    LoggingEngine::getInstance().addSink(std::make_shared<FileLogSink>(filename), level);
}

void ConfigurationManager::applyFileSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const std::string_view& filename) {
    auto sink = std::make_shared<FileLogSink>(filename);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
}

void ConfigurationManager::applyFileSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const std::string_view& filename) {
    auto sink = std::make_shared<FileLogSink>(filename);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
}

void ConfigurationManager::applyFileSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const std::string_view& filename) {
    auto sink = std::make_shared<FileLogSink>(filename);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
}

void ConfigurationManager::applyFileSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const utils::LogLevel& level5, const std::string_view& filename) {
    auto sink = std::make_shared<FileLogSink>(filename);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
    logger.addSink(sink, level5);
}

// --- Network sink ---

void ConfigurationManager::applyNetworkSink(const utils::LogLevel& level, const std::string_view& url) {
    LoggingEngine::getInstance().addSink(std::make_shared<NetworkLogSink>(url), level);
}

void ConfigurationManager::applyNetworkSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const std::string_view& url) {
    auto sink = std::make_shared<NetworkLogSink>(url);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
}

void ConfigurationManager::applyNetworkSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const std::string_view& url) {
    auto sink = std::make_shared<NetworkLogSink>(url);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
}

void ConfigurationManager::applyNetworkSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const std::string_view& url) {
    auto sink = std::make_shared<NetworkLogSink>(url);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
}

void ConfigurationManager::applyNetworkSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const utils::LogLevel& level5, const std::string_view& url) {
    auto sink = std::make_shared<NetworkLogSink>(url);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
    logger.addSink(sink, level5);
}

// --- Database sink ---

void ConfigurationManager::applyDataBaseSink(const utils::LogLevel& level, const std::string_view& database) {
    LoggingEngine::getInstance().addSink(std::make_shared<DataBaseLogSink>(database), level);
}

void ConfigurationManager::applyDataBaseSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const std::string_view& database) {
    auto sink = std::make_shared<DataBaseLogSink>(database);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
}

void ConfigurationManager::applyDataBaseSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const std::string_view& database) {
    auto sink = std::make_shared<DataBaseLogSink>(database);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
}

void ConfigurationManager::applyDataBaseSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const std::string_view& database) {
    auto sink = std::make_shared<DataBaseLogSink>(database);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
}

void ConfigurationManager::applyDataBaseSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const utils::LogLevel& level5, const std::string_view& database) {
    auto sink = std::make_shared<DataBaseLogSink>(database);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
    logger.addSink(sink, level5);
}

// --- Syslog sink ---

#ifdef __unix__
void ConfigurationManager::applySysLogSink(const utils::LogLevel& level, const std::string_view& ident) {
    LoggingEngine::getInstance().addSink(std::make_shared<SysLogSink>(ident), level);
}

void ConfigurationManager::applySysLogSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const std::string_view& ident) {
    auto sink = std::make_shared<SysLogSink>(ident);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
}

void ConfigurationManager::applySysLogSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const std::string_view& ident) {
    auto sink = std::make_shared<SysLogSink>(ident);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
}

void ConfigurationManager::applySysLogSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const std::string_view& ident) {
    auto sink = std::make_shared<SysLogSink>(ident);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
}

void ConfigurationManager::applySysLogSink(const utils::LogLevel& level1, const utils::LogLevel& level2, const utils::LogLevel& level3, const utils::LogLevel& level4, const utils::LogLevel& level5, const std::string_view& ident) {
    auto sink = std::make_shared<SysLogSink>(ident);
    auto& logger = LoggingEngine::getInstance();
    logger.addSink(sink, level1);
    logger.addSink(sink, level2);
    logger.addSink(sink, level3);
    logger.addSink(sink, level4);
    logger.addSink(sink, level5);
}
#endif
