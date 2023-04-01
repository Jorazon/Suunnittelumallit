#pragma once

#include <string>

class PaymentProcessor {
public:
  virtual bool ProcessPayment(const std::string& customer_id, float amount) = 0;
};
