#include "Thread.h"
#include "Logging.h"

#include <iostream>


void threadFuncTest()
{
    while (true)
    {
        CurrentThread::sleepForMillisec(3000);
        LOG << "threadFuncTest\n";
    }
}

int main(int argc, char* argv[])
{
    Thread thread1(threadFuncTest, "thread1");
    thread1.start();
    thread1.join();
    return 0;
}