#pragma once

class CompetitionSecretary {
public:
  // code to calculate the final results
  float calculate(float distance) {
    return 1.2f * (distance - 120.0f);
  }
};
