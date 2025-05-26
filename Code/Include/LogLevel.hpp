#pragma once

namespace Debug
{
    enum class LogLevel : unsigned int
    {
        VERBOSE = 0,
        INFO = 1,
        WARNING = 2,
        ERROR = 3,
        CRITICAL = 4
    };
}