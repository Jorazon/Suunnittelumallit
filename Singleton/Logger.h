#pragma once

#include <string>

class Logger {
public:
  enum LoggingLevel {
    ALL = 0,
    DEBUG = 1,
    INFO = 2,
    WARNING = 4,
    ERROR = 8,
    OFF = 16,
  };

  static Logger* GetInstance() {
    if (!instance) {
      instance = new Logger();
    }
    return instance;
  }

  void SetLevel(LoggingLevel level) {
    loggingLevel = level;
  }

  void Log(std::string message, LoggingLevel level) {
    if (loggingLevel != OFF && loggingLevel <= level) {
      const char* levelstr;

      switch (level)
      {
      case ALL:
        levelstr = "ALL";
        break;
      case DEBUG:
        levelstr = "DEBUG";
        break;
      case INFO:
        levelstr = "INFO";
        break;
      case WARNING:
        levelstr = "WARNING";
        break;
      case ERROR:
        levelstr = "ERROR";
        break;
      case OFF:
        levelstr = "OFF";
        break;
      default:
        levelstr = "";
        break;
      }

      printf("%s: %s\n", levelstr, message.c_str());
    }
  }
private:
  static Logger* instance;
  LoggingLevel loggingLevel;
  Logger() { loggingLevel = ALL; }
  Logger(const Logger&) { loggingLevel = ALL; }
  void operator = (const Logger&) { loggingLevel = ALL; }
};

Logger* Logger::instance;
