#include "loggerCpp/configurationManager.hpp"

ConfigurationManager::ConfigurationManager() {
    auto& logger = LoggingEngine::getInstance();
#ifdef NDEBUG
    logger.setLogLevel(utils::LogLevel::INFO);
#else
    logger.setLogLevel(utils::LogLevel::DEBUG);
#endif
}

ConfigurationManager::ConfigurationManager(utils::LogLevel logLevel) {
    LoggingEngine::getInstance().setLogLevel(logLevel);
}
