#pragma once

#include <ctime>
#include <thread>
#include <chrono>
#include <functional>

#include "Observable.h"

class TimeServer : public Observable {
public:
  void Start() {
    timeState = std::time(nullptr);
    std::thread T1(Task, this);
    thread = &T1;
    thread->detach();
  }
  void Stop() {
    if (thread) thread->~thread();
  }
  std::time_t GetTime() { return timeState; }
private:
  static void Task(TimeServer* server) {
    for (;;) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      server->timeState++;
      server->Notify();
    }
  }
  std::thread* thread = nullptr;
  std::time_t timeState = 0;
};
