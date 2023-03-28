#pragma warning(disable : 6031)

#include <iostream>

#include "Mediator.h"
#include "Jumper.h"
#include "Measurer.h"
#include "Judge.h"
#include "Scoreboard.h"
#include "ResultRow.h"

int main() {
  Mediator mediator;

  Jumper jumper("Kazuyoshi Funaki");

  Measurer measurer;

  Judge judge1;
  Judge judge2;
  Judge judge3;
  Judge judge4;
  Judge judge5;

  CompetitionSecretary secretary;

  Scoreboard scoreboard;
  ResultRow resultrow;

  mediator.registerJumper(&jumper);
  mediator.registerMeasurer(&measurer);

  mediator.registerJudge(&judge1);
  mediator.registerJudge(&judge2);
  mediator.registerJudge(&judge3);
  mediator.registerJudge(&judge4);
  mediator.registerJudge(&judge5);

  mediator.registerSecretery(&secretary);

  mediator.registerScoreboard(&scoreboard);
  mediator.registerResultRow(&resultrow);
  
  mediator.jump();
  mediator.jump();

  mediator.displayResults();

  getchar();
}
