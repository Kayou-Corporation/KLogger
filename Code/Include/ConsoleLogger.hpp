#pragma once

#include "ILogger.hpp"


namespace KLogger
{
    class ConsoleLogger : public ILogger
    {
        void Log(const LogLevel& logLevel, const LogChannel& logChannel, const std::string& logMessage) override;
        void LogVerbose() override;
        void LogInfo() override;
        void LogWarning() override;
        void LogError() override;
        void LogCritical() override;

        void Assert() override;
        void Throw() override;
    };
}