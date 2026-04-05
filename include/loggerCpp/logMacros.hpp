// logMacros.hpp — intentionally NO #pragma once.
//
// <syslog.h> defines LOG_DEBUG=7, LOG_INFO=6, etc. as plain integers.
// Because those names can arrive from any transitive include (gtkmm, glib,
// posix headers…), the only reliable way to guarantee our function-like
// macros win is to include this file LAST in every translation unit that
// uses them — without the include-guard that would stop it from running.

#ifdef LOG_DEBUG
#undef LOG_DEBUG
#endif
#ifdef LOG_INFO
#undef LOG_INFO
#endif
#ifdef LOG_WARNING
#undef LOG_WARNING
#endif
#ifdef LOG_ERROR
#undef LOG_ERROR
#endif
#ifdef LOG_CRITICAL
#undef LOG_CRITICAL
#endif
#ifdef LOG_TRACE
#undef LOG_TRACE
#endif

// NOLINTBEGIN(cppcoreguidelines-macro-usage)
#define LOG_DEBUG(msg, ...)    [[unlikely]] LoggingEngine::getInstance().log(utils::LogLevel::DEBUG,    std::source_location::current(), fmt::format(msg, ##__VA_ARGS__))
#define LOG_INFO(msg, ...)     [[unlikely]] LoggingEngine::getInstance().log(utils::LogLevel::INFO,     std::source_location::current(), fmt::format(msg, ##__VA_ARGS__))
#define LOG_WARNING(msg, ...)  [[unlikely]] LoggingEngine::getInstance().log(utils::LogLevel::WARNING,  std::source_location::current(), fmt::format(msg, ##__VA_ARGS__))
#define LOG_ERROR(msg, ...)    [[unlikely]] LoggingEngine::getInstance().log(utils::LogLevel::ERROR,    std::source_location::current(), fmt::format(msg, ##__VA_ARGS__))
#define LOG_CRITICAL(msg, ...) [[unlikely]] LoggingEngine::getInstance().log(utils::LogLevel::CRITICAL, std::source_location::current(), fmt::format(msg, ##__VA_ARGS__))
#define LOG_TRACE(msg, ...)    [[unlikely]] LoggingEngine::getInstance().log(utils::LogLevel::TRACE,    std::source_location::current(), fmt::format(msg, ##__VA_ARGS__))
// NOLINTEND(cppcoreguidelines-macro-usage)
