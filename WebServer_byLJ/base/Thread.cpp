// @Author Jiang Lan
// @Email brahmsjiang@163.com
#include "Thread.h"

#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <memory>
#include <iostream>

using namespace std;

namespace CurrentThread {
    void sleepForMillisec(int x)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(x));
    }
    Tid tid()
    {
        return std::this_thread::get_id();
    }
}

Thread::Thread(const ThreadFunc& func, const string& name)
    : func_(func),
    name_(name)
{
    setDefaultName();
}

Thread::~Thread() {
    assert(started_);
    assert(!joined_);

    if (nullptr != thread_)
    {
        thread_->detach();
    }
}

void Thread::setDefaultName() {
  if (name_.empty()) {
    char buf[32];
    snprintf(buf, sizeof buf, "Thread");
    name_ = buf;
  }
}

void Thread::start()
{
    assert(!started_);
    started_ = true;
    
    thread_ = std::make_shared<std::thread>(func_);
}

void Thread::join()
{
  assert(started_);
  assert(!joined_);
  joined_ = true;
  
  if (nullptr != thread_ && thread_->joinable())
  {
      thread_->join();
      thread_.reset();
  }
}