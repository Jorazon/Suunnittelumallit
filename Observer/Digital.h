#pragma once

#include <time.h>
#include <iostream>

#include "Observer.h"
#include "Observable.h"
#include "TimeServer.h"

class Digital : public Observer {
public:
  Digital(TimeServer *server) {
    server->Attach(this);
  }

  void Update(Observable* observable) {
    TimeServer* server = (TimeServer*) observable;
    std::time_t time = server->GetTime();
    tm timestruct;
    localtime_s(&timestruct, &time);
    printf("%02d:%02d:%02d\n", timestruct.tm_hour, timestruct.tm_min, timestruct.tm_sec);
  };
};
