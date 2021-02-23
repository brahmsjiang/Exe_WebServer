// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#pragma once
#include <stdio.h>
#include <string.h>
#include <string>


class Logger
{
public:
    Logger(const char* fileName, int line);
    ~Logger();

    static void setLogFileName(std::string fileName) { logFileName_ = fileName; }
    static std::string getLogFileName() { return logFileName_; }

private:
    class LoggerImpl
    {
    public:
        LoggerImpl(const char* fileName, int line);
        void formatPrefix();

        int line_;
        std::string basename_;
    };

    LoggerImpl* impl_;
    static std::string logFileName_;
};

#define LOG Logger(__FILE__, __LINE__).stream()