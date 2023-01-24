#pragma warning(disable : 6031)

#include "Logger.h"

void logtest(Logger *logger);

int main() {
  Logger *logger = Logger::GetInstance();

  logtest(logger);
  logger->SetLevel(Logger::DEBUG);
  logtest(logger);
  logger->SetLevel(Logger::INFO);
  logtest(logger);
  logger->SetLevel(Logger::WARNING);
  logtest(logger);
  logger->SetLevel(Logger::ERROR);
  logtest(logger);
  logger->SetLevel(Logger::OFF);
  logtest(logger);

  getchar();
}

void logtest(Logger* logger) {
  logger->Log("All test", Logger::ALL);
  logger->Log("Debug test", Logger::DEBUG);
  logger->Log("Info test", Logger::INFO);
  logger->Log("Warning test", Logger::WARNING);
  logger->Log("Error test", Logger::ERROR);
  printf("------------------\n");
}
