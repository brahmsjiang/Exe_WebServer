#include "Thread.h"
#include <iostream>


void threadFuncTest()
{
    while (true)
    {
        CurrentThread::sleepForMillisec(3000);
        std::cout << "threadFuncTest" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    Thread thread1(threadFuncTest, "thread1");
    thread1.start();
    thread1.join();
    return 0;
}