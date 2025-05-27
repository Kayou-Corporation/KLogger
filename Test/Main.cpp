#include <iostream>

#include "Logger.hpp"
using KLogger::Utils::operator""_MiB;


int main()
{
    std::cout << "Test\n";

    try
    {
        KLogger::Logger::Get().Init();
        std::cout << "Success!\n";
    }
    catch (_exception)
    {
    }

    getchar();
    return 0;
}
