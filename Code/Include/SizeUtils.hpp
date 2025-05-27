#pragma once

namespace KLogger::Utils
{
    static constexpr size_t operator""_KiB(const unsigned long long int a_x) { return 1024ULL * a_x; }
    static constexpr size_t operator""_MiB(const unsigned long long int a_x) { return 1024_KiB * a_x; }
}