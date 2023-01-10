#pragma once

#include "AterioivaOtus.h"
#include "Vesi.h"
#include "Salaatti.h"

class Opettaja : public AterioivaOtus
{
public:
  Juoma* CreateJuoma();
  Ruoka* CreateRuoka();
};
