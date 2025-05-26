#pragma once

#include "ILogger.hpp"


#define KLOG(level, ...) KLogger::Logger::GetInstance().Log(level, Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_VERBOSE(...) KLogger::Logger::GetInstance().LogVerbose(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_INFO(...) KLogger::Logger::GetInstance().LogInfo(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_WARNING(...) KLogger::Logger::GetInstance().LogWarning(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_ERROR(...) KLogger::Logger::GetInstance().LogError(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))
#define KLOG_CRITICAL(...) KLogger::Logger::GetInstance().LogCritical(Debug::Logger::FormatLocation(fmt::format(__VA_ARGS__)))


namespace KLogger
{
    class ConsoleLogger : public ILogger
    {
        void Log(const Debug::LogLevel& logLevel, const LogChannel& logChannel, const std::string& logMessage) override;
        void LogVerbose() override;
        void LogInfo() override;
        void LogWarning() override;
        void LogError() override;
        void LogCritical() override;

        void Assert() override;
        void Throw() override;
    };
}