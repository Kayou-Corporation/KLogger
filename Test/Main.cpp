#include <iostream>

#include "Logger.hpp"
using KLogger::Utils::operator""_MiB;


int main()
{
    std::cout << "Test\n";

    try
    {
        KLogger::Logger::Get().Init("MyLogger", 1_MiB, 3, true);
        std::cout << "Success!\n";
    }
    catch (_exception)
    {
    }

    getchar();
    return 0;
}
