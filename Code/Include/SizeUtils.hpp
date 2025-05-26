#pragma once

namespace KLogger::Utils
{
    inline static constexpr size_t operator""_KiB(const unsigned long long int a_x) { return 1024ULL * a_x; }
    inline static constexpr size_t operator""_MiB(const unsigned long long int a_x) { return 1024_KiB * a_x; }
}