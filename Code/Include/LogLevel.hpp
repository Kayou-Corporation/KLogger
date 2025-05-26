#pragma once

#include <cstdint>


namespace KLogger
{
    enum class LogLevel : uint16_t
    {
        TRACE       = 0x0001,   // 1
        INFO        = 0x0002,   // 2
        WARNING     = 0x0004,   // 4
        ERROR       = 0x0008,   // 8
        CRITICAL    = 0x0010    // 16
    };
}
