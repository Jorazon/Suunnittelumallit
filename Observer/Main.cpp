#pragma warning(disable : 6031)

#include "TimeServer.h"
#include "Digital.h"

int main() {
  TimeServer *server = new TimeServer();
  server->Start();
  
  Digital clock(server);

  getchar();
}
