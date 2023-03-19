#pragma once

#include <iostream>

#include "Prototype.h"
#include "Hand.h"

// Class for a clock that consists of two hands
class Clock : public Prototype {
public:
  Clock() : m_hourHand(0), m_minuteHand(0), m_secondHand(0) {}

  // Implement the clone method from the Prototype interface
  Clock* clone() const override {
    Clock *clone = new Clock();
    clone->m_hourHand = *m_hourHand.clone();
    clone->m_minuteHand = *m_minuteHand.clone();
    clone->m_secondHand = *m_secondHand.clone();
    return clone;
  }

  // Set the time on the clock
  void setTime(int hours, int minutes, int seconds) {
    m_hourHand.move((hours + minutes / 60 + seconds / 3600) % 12);
    m_minuteHand.move((minutes + seconds / 60) % 60);
    m_secondHand.move(seconds % 60);
  }

  // Print the current time on the clock
  void printTime() const {
    std::cout << "Current time: "
      << m_hourHand << ":"
      << m_minuteHand << ":"
      << m_secondHand << std::endl;
  }

private:
  Hand m_hourHand;
  Hand m_minuteHand;
  Hand m_secondHand;
};
