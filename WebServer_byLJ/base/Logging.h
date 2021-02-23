// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#pragma once
#include <stdio.h>
#include <string.h>
#include <string>
#include <memory>

class Logger
{
public:
    Logger(const char* fileName, int line);
    ~Logger();

private:
	class LoggerImpl;
    std::unique_ptr<LoggerImpl> impl_;
};

#define LOG Logger(__FILE__, __LINE__).stream()