#pragma once

#include <source_location>

#include "LogChannel.hpp"
#include "LogContent.hpp"
#include "LogLevel.hpp"


namespace KLogger
{
    class ILogger
    {
    public:
        virtual ~ILogger() = default;

        virtual void Log(const LogContent& content) = 0;
        virtual void LogVerbose() = 0;
        virtual void LogInfo() = 0;
        virtual void LogWarning() = 0;
        virtual void LogError() = 0;
        virtual void LogCritical() = 0;

        virtual void Assert() = 0;
        virtual void Throw() = 0;


    protected:
        struct FormatLocation
        {
            std::string_view format;
            std::source_location location;

            template <typename LogMessage>
            explicit FormatLocation(LogMessage&& a_logMessage, const std::source_location a_location = std::source_location::current())
                                    : format(std::forward<LogMessage>(a_logMessage)), location(a_location) { }
        };
    };
}
