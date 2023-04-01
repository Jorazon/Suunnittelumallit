#pragma once

#include <string>

#include "PaymentProcessor.h"
#include "PaymentGateway.h"

class PaymentGatewayAdapter : public PaymentProcessor {
public:
  PaymentGatewayAdapter(const PaymentGateway& payment_gateway) : payment_gateway_(payment_gateway) {}
  bool ProcessPayment(const std::string& customerId, float amount) override {
    bool success = payment_gateway_.ChargeCustomer(customerId, amount);
    return success;
  }
private:
  const PaymentGateway& payment_gateway_;
};
