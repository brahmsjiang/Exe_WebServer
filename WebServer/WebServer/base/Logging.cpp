// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#include "Logging.h"
#include "CurrentThread.h"
#include "Thread.h"
#include "AsyncLogging.h"
#include <assert.h>
#include <iostream>
#include <time.h>  
#include <sys/time.h> 


static pthread_once_t once_control_ = PTHREAD_ONCE_INIT;
static AsyncLogging *AsyncLogger_;

std::string Logger::logFileName_ = "./WebServer.log";

void once_init()
{
    AsyncLogger_ = new AsyncLogging(Logger::getLogFileName());
    AsyncLogger_->start(); 
}

void flushToFile(const char* msg, int len)
{
    pthread_once(&once_control_, once_init);
    AsyncLogger_->append(msg, len);
}

void flushToStdout(const char* msg, int len)
{
    fwrite(msg, 1, len, stdout);

}

Logger::Impl::Impl(const char *fileName, int line)
  : stream_(),
    line_(line),
    basename_(fileName)
{
    formatPrefix();
}

void Logger::Impl::formatPrefix()
{
    struct timeval tv;
    time_t time;
    char str_t[26] = {0};
    gettimeofday(&tv, NULL);
    time = tv.tv_sec;
    struct tm* p_time = localtime(&time);   
    strftime(str_t, 26, "%Y-%m-%d %H:%M:%S\t", p_time);

    stream_ << CurrentThread::tid() << " ";
    stream_ << str_t;
}

Logger::Logger(const char *fileName, int line)
  : impl_(fileName, line)
{ }

Logger::~Logger()
{
    //impl_.stream_ << " -- " << impl_.basename_ << ':' << impl_.line_ << '\n';
    const LogStream::Buffer& buf(stream().buffer());
    flushToFile(buf.data(), buf.length());

    flushToStdout(buf.data(), buf.length());
    
}