#pragma once


class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void Log() = 0;

};