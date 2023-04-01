#pragma warning(disable : 6031)

#include <iostream>

#include "PaymentGateway.h"
#include "PaymentGatewayAdapter.h"
#include "PaymentProcessor.h"

void EcommerceClient(PaymentProcessor& payment_processor);

int main() {
  PaymentGateway third_party_payment_gateway;

  PaymentGatewayAdapter payment_gateway_adapter(third_party_payment_gateway);

  EcommerceClient(payment_gateway_adapter);

  getchar();
}

void EcommerceClient(PaymentProcessor& payment_processor) {
  bool paymentSuccess = payment_processor.ProcessPayment("12345", 99.99f);
  if (paymentSuccess) {
    std::cout << "Payment processed successfully" << std::endl;
  }
  else {
    std::cout << "Payment failed" << std::endl;
  }
}
