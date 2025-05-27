#include "Logger.hpp"


void KLogger::Logger::Init(const std::string& loggerName, const size_t maxFileSize, const size_t maxLogFiles, const bool useColors)
{
    m_loggerName = loggerName;
    m_maxFileSize = maxFileSize;
    m_maxLogFiles = maxLogFiles;
    m_useColors = useColors;
}
