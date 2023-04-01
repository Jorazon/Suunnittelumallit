#pragma once

#include <iostream>

class PaymentGateway {
public:
  bool ChargeCustomer(const std::string& customer_id, float amount) const {
    std::cout << "PaymentGateway::ChargeCustomer called with customer ID " << customer_id
      << " and amount " << amount << std::endl;
    return true;
  }
};
