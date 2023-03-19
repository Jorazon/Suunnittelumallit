#pragma once

#include <iostream>

#include "Prototype.h"

// Class for a clock hand
class Hand : public Prototype {
public:
  Hand(int position) : m_position(position) {}

  // Implement the clone method from the Prototype interface
  Hand* clone() const override {
    return new Hand(m_position);
  }

  // Move the hand to a new position
  void move(int position) {
    m_position = position;
  }

  // Print the current position of the hand
  friend std::ostream& operator<<(std::ostream& os, Hand hand)
  {
    return os << (hand.m_position < 10 ? "0" : "") << hand.m_position;
  }

private:
  int m_position;
};
