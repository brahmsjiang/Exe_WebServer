// @Author Jiang Lan
// @Email brahmsjiang@163.com
#include "Logging.h"
#include "Thread.h"
#include "LogStream.h"

#include <assert.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

void flushToStdout(const char* msg, int len)
{
    fwrite(msg, 1, len, stdout);
}

class LoggerImpl
{
public:
	LoggerImpl(const char* fileName, int line);
	void formatPrefix();
private:
	LogStream stream_;
	std::string basename_;
	int line_;
};



LoggerImpl::LoggerImpl(const char* fileName, int line)
  : basename_(fileName),
	line_(line)
{
    formatPrefix();
}

void LoggerImpl::formatPrefix()
{
	auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	char str_t[32] = { 0 };

	std::localtime(&tt);

	//stream_ << std::put_time(std::localtime(&tt), "%Y-%m-%d %H:%M:%S\t");
	stream_ << CurrentThread::tid() << " ";
	stream_ << str_t;
}

Logger::Logger(const char *fileName, int line)
	: impl_(std::make_unique<LoggerImpl>())
{

}

Logger::~Logger()
{
    //impl_.stream_ << " -- " << impl_.basename_ << ':' << impl_.line_ << '\n';
    const LogStream::Buffer& buf(stream().buffer());

    flushToStdout(buf.data(), buf.length());
    
}