#pragma once

class Scoreboard {
public:
  // Display the length and score on the scoreboard
  void display(float length, float points, float score) {
    printf(
      "Distance: %.1f\t"
      "Points: %.1f\t"
      "Style: %.1f\t"
      "Total: %.1f\n",
      length,
      points,
      score,
      points + score
    );
  }
};
