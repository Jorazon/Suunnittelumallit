#pragma once

#include "Ruoka.h"

class Salaatti : public Ruoka
{
private:
  const char* GetNimi() { return "salaatti"; }
};
