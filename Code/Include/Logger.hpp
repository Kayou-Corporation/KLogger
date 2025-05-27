#pragma once

#include <string>
#include <vector>

#include "ILogger.hpp"
#include "LogContent.hpp"
#include "SizeUtils.hpp"
using KLogger::Utils::operator""_MiB;


#define KLOG(level, ...) KLogger::Logger::GetInstance().Log(level, KLogger::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_VERBOSE(...) KLogger::Logger::GetInstance().LogVerbose(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_INFO(...) KLogger::Logger::GetInstance().LogInfo(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_WARNING(...) KLogger::Logger::GetInstance().LogWarning(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_ERROR(...) KLogger::Logger::GetInstance().LogError(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_CRITICAL(...) KLogger::Logger::GetInstance().LogCritical(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))



namespace KLogger
{
    class Logger
    {
    public:
        explicit Logger() = default;
        ~Logger() = default;

        Logger(const Logger&) = delete; // Prevents singleton copy
        Logger(Logger&&) = delete; // Prevents singleton copy
        Logger& operator=(const Logger&) = delete; // Prevents singleton assignment
        Logger& operator=(Logger&&) = delete; // Prevents singleton assignment

        /// @param loggerName The name of the logger (used as the name of the logger file)
        /// @param maxFileSize The max size for each log file
        /// @param maxLogFiles The max amount of log files to keep before erasing the oldest one
        /// @param useColors Whether to use colors in console or not
        void Init(const std::string& loggerName, size_t maxFileSize, size_t maxLogFiles, bool useColors);


        /// @return Returns the instance of the logger
        inline static Logger& Get() { static Logger instance; return instance; }


        void Log(const LogContent& content) { if (m_logger) m_logger->Log(content); }


    private:
        std::string m_loggerName = "KLogger";
        size_t m_maxFileSize = 1_MiB;
        size_t m_maxLogFiles = 3;
        bool m_useColors = true;
        bool m_stopLogger = false;
        bool m_useFileLogger = true;
        bool m_useConsoleLogger = true;

        std::vector<std::string> m_logBuffer = {};
        size_t m_bufferSize = 0;

        std::unique_ptr<ILogger> m_logger = nullptr;
    };
}
