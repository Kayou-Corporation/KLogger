#pragma once

#include <string_view>
#include <source_location>

#include "LogChannel.hpp"
#include "LogLevel.hpp"


namespace KLogger
{
    struct LogContent
    {
        LogLevel level = LogLevel::TRACE;
        LogChannel channel = LogChannel("Global");
        std::string_view message;
        std::source_location location = std::source_location::current();

        template <typename Message>
        inline explicit LogContent(Message&& logMessage, const LogLevel logLevel = LogLevel::TRACE, const LogChannel logChannel = LogChannel("Global"), std::source_location logLocation = std::source_location::current())
                            : level(logLevel), channel(logChannel), message(std::forward<Message>(logMessage)) {}
    };
}
