#pragma once

#include "LogChannel.hpp"
#include "LogLevel.hpp"



namespace KLogger
{
    class ILogger
    {
    public:
        virtual ~ILogger() = default;

        virtual void Log(const Debug::LogLevel& logLevel, const LogChannel& logChannel, const std::string& logMessage) = 0;
        virtual void LogVerbose() = 0;
        virtual void LogInfo() = 0;
        virtual void LogWarning() = 0;
        virtual void LogError() = 0;
        virtual void LogCritical() = 0;

        virtual void Assert() = 0;
        virtual void Throw() = 0;
    };
}