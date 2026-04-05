#pragma once

#include <string_view>
#include <memory>

// sysLogSink.hpp pulls in <syslog.h> which defines LOG_DEBUG/LOG_INFO/etc.
// as plain integers. It MUST be included before loggingEngine.hpp so that
// utils.hpp can #undef those names and replace them with our function-like
// macros AFTER syslog.h has already run.
#ifdef __unix__
#include "sysLogSink.hpp"
#endif
#include "loggingEngine.hpp"
#include "consoleLogSink.hpp"
#include "fileLogSink.hpp"
#include "dataBaseLogSink.hpp"
#include "networkLogSink.hpp"

/**
 * @brief Configures the logging system with sinks and log levels.
 *
 * Each apply*Sink call accepts one or more minimum log levels. With fixed
 * minimum-level routing a single level is usually enough; multiple levels
 * create multiple independent sink instances (e.g. one sink per level).
 *
 * Example:
 *   ConfigurationManager cfg;
 *   cfg.applyConsoleSink(utils::LogLevel::DEBUG);          // console ≥ DEBUG
 *   cfg.applyFileSink(utils::LogLevel::INFO, "app.log");   // file ≥ INFO
 */
class ConfigurationManager {
public:
    /// Sets global log level to DEBUG in debug builds, INFO in release.
    ConfigurationManager();

    /// Sets global log level explicitly.
    explicit ConfigurationManager(utils::LogLevel logLevel);

    ~ConfigurationManager() noexcept = default;
    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;
    ConfigurationManager(ConfigurationManager&&) noexcept = default;
    ConfigurationManager& operator=(ConfigurationManager&&) noexcept = default;

    // ── Console ─────────────────────────────────────────────────────────────
    template<typename... Levels>
        requires (sizeof...(Levels) >= 1) &&
                 (std::same_as<std::remove_cvref_t<Levels>, utils::LogLevel> && ...)
    void applyConsoleSink(Levels... levels) {
        auto& logger = LoggingEngine::getInstance();
        (logger.addSink(std::make_shared<ConsoleLogSink>(), levels), ...);
    }

    // ── File ────────────────────────────────────────────────────────────────
    template<typename... Levels>
        requires (sizeof...(Levels) >= 1) &&
                 (std::same_as<std::remove_cvref_t<Levels>, utils::LogLevel> && ...)
    void applyFileSink(std::string_view filename, Levels... levels) {
        auto& logger = LoggingEngine::getInstance();
        (logger.addSink(std::make_shared<FileLogSink>(filename), levels), ...);
    }

    // ── Network ─────────────────────────────────────────────────────────────
    template<typename... Levels>
        requires (sizeof...(Levels) >= 1) &&
                 (std::same_as<std::remove_cvref_t<Levels>, utils::LogLevel> && ...)
    void applyNetworkSink(std::string_view url, Levels... levels) {
        auto& logger = LoggingEngine::getInstance();
        (logger.addSink(std::make_shared<NetworkLogSink>(url), levels), ...);
    }

    // ── Database ────────────────────────────────────────────────────────────
    template<typename... Levels>
        requires (sizeof...(Levels) >= 1) &&
                 (std::same_as<std::remove_cvref_t<Levels>, utils::LogLevel> && ...)
    void applyDataBaseSink(std::string_view database, Levels... levels) {
        auto& logger = LoggingEngine::getInstance();
        (logger.addSink(std::make_shared<DataBaseLogSink>(database), levels), ...);
    }

#ifdef __unix__
    // ── Syslog ──────────────────────────────────────────────────────────────
    template<typename... Levels>
        requires (sizeof...(Levels) >= 1) &&
                 (std::same_as<std::remove_cvref_t<Levels>, utils::LogLevel> && ...)
    void applySysLogSink(std::string_view ident, Levels... levels) {
        auto& logger = LoggingEngine::getInstance();
        (logger.addSink(std::make_shared<SysLogSink>(ident), levels), ...);
    }
#endif
};
