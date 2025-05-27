#pragma once

#include <string>
#include <vector>

#include "ILogger.hpp"
#include "LogContent.hpp"
#include "SizeUtils.hpp"
using KLogger::Utils::operator""_MiB;


#define KLOG(level, ...) KLogger::Logger::Get().Log(level, KLogger::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_VERBOSE(...) KLogger::Logger::Get().LogVerbose(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_INFO(...) KLogger::Logger::Get().LogInfo(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_WARNING(...) KLogger::Logger::Get().LogWarning(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_ERROR(...) KLogger::Logger::Get().LogError(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_CRITICAL(...) KLogger::Logger::Get().LogCritical(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))



namespace KLogger
{
    struct Config
    {
        bool enableColorSupport = true;
        bool enableConsoleLogger = true;
        bool enableFileLogger = true;

        std::string m_loggerName = "KLogger";
        size_t m_maxFileSize = 1_MiB;
        size_t m_maxLogFiles = 3;
    };

    class Logger
    {
    public:
        ~Logger() = default;

        Logger(const Logger&) = delete; // Prevents singleton copy
        Logger(Logger&&) = delete; // Prevents singleton copy
        Logger& operator=(const Logger&) = delete; // Prevents singleton assignment
        Logger& operator=(Logger&&) = delete; // Prevents singleton assignment

        /// @param config
        void Init(const Config& config);


        /// @return Returns the instance of the logger
        inline static Logger& Get() { static Logger instance; return instance; }


        inline void Log(const LogContent& content) const { if (m_logger) m_logger->Log(content); }


    private:
        explicit Logger() = default;

        std::vector<std::string> m_logBuffer = {};
        size_t m_bufferSize = 0;

        std::unique_ptr<ILogger> m_logger = nullptr;
    };
}
