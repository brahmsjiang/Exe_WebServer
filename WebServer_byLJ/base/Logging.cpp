// @Author Jiang Lan
// @Email brahmsjiang@163.com
#include "Logging.h"
#include "Thread.h"
#include "LogStream.h"

#include <time.h>
#include <assert.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

void flushToStdout(const char* msg, int len)
{
    fwrite(msg, 1, len, stdout);
}

class Logger::Impl
{
public:
	Impl(const char* fileName, int line)
	  : basename_(fileName),
		line_(line)
	{
		formatPrefix();
	}

	void formatPrefix()
	{
		auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());		
		struct tm *info = std::localtime(&tt);

		stream_ << CurrentThread::tid() << " ";
		stream_ << asctime(info);
	}
	
	LogStream stream_;
	std::string basename_;
	int line_;
};



Logger::Logger(const char *fileName, int line)
	: impl_(std::make_unique<Impl>(fileName, line))
{

}

Logger::~Logger()
{
    //impl_.stream_ << " -- " << impl_.basename_ << ':' << impl_.line_ << '\n';
    const LogStream::Buffer& buf(stream().buffer());

    flushToStdout(buf.data(), buf.length());
    
}

LogStream& Logger::stream()
{
	return impl_->stream_;
}
