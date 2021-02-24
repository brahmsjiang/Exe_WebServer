// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#pragma once

#include <functional>
#include <memory>
#include <string>
#include <thread>
#include <memory>

namespace CurrentThread {
    void sleepForMillisec(int x);
    unsigned tid();
}

class Thread
{
public:
  using ThreadFunc = std::function<void()>;

  explicit Thread(const ThreadFunc&, const std::string& name = std::string());
  ~Thread();
  Thread(const Thread&) = delete;
  Thread& operator=(const Thread&) = delete;

  void start();
  void join();
  bool started() const { return started_; }
  std::thread::id gettid() const { return tid_; }
  const std::string& name() const { return name_; }

 private:
  void setDefaultName();

  std::shared_ptr<std::thread> thread_;
  bool started_ = false;
  bool joined_ = false;
  std::thread::id tid_;
  ThreadFunc func_;
  std::string name_;

};