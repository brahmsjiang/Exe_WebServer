// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#pragma once
#include <stdio.h>
#include <string.h>
#include <string>
#include <memory>

class LogStream;

class Logger
{
public:
    Logger(const char* fileName, int line);
    ~Logger();
	LogStream& stream();

private:
	class Impl;
    std::unique_ptr<Impl> impl_;
};

#define LOG Logger(__FILE__, __LINE__).stream()