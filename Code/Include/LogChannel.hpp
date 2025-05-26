#pragma once

#include <sstream>
#include <string>


namespace KLogger
{
    class LogChannel
    {
    public:
        explicit LogChannel(std::string name) : channelName(std::move(name)) {}

        const std::string& GetChannel() const { return channelName; }
        const char* GetChannelStr() const { return channelName.c_str(); }
        const std::vector<std::string>& GetSubChannels() const { return subChannels; }


    private:
        std::string channelName;
        std::vector<std::string> subChannels;

        inline static std::vector<std::string> splitMultipleDelimiters(const std::string& string, const std::string& delimiters = ".:")
        {
            std::vector<std::string> parts;
            size_t start = 0;
            size_t pos = 0;

            while (pos < string.size())
            {
                const size_t delimPos = string.find_first_of(delimiters, pos);

                if (delimPos == std::string::npos)
                {
                    parts.push_back(string.substr(start));
                    break;
                }

                parts.push_back(string.substr(start, delimPos - start));
                pos = delimPos + 1;
                start = pos;
            }

            return parts;
        }

        inline void SplitChannels() { subChannels = splitMultipleDelimiters(channelName, ".:"); }
    };
}