#pragma once

#include <vector>

#include "Jumper.h"
#include "Jump.h"
#include "Measurer.h"
#include "Judge.h"
#include "Scoreboard.h"
#include "ResultRow.h"
#include "CompetitionSecretary.h"

class Mediator {
private:
  Jumper* jumper_ = nullptr;
  Measurer* measurer_ = nullptr;
  std::vector<Judge*> judges_ = std::vector<Judge*>();
  Scoreboard* score_board_ = nullptr;
  ResultRow* result_row_ = nullptr;
  CompetitionSecretary* competition_secretary_ = nullptr;

public:
  void registerJumper(Jumper* jumper) {
    jumper_ = jumper;
  }

  void registerMeasurer(Measurer* measurer) {
    measurer_ = measurer;
  }

  void registerJudge(Judge* judge) {
    judges_.push_back(judge);
  }

  void registerSecretery(CompetitionSecretary* secretary) {
    competition_secretary_ = secretary;
  }

  void registerScoreboard(Scoreboard* scoreboard) {
    score_board_ = scoreboard;
  }

  void registerResultRow(ResultRow* resultrow) {
    result_row_ = resultrow;
  }

  void jump() {
    if (!jumper_) return;
    if (!measurer_) return;
    if (!score_board_) return;
    if (!competition_secretary_) return;
    
    Jump* jump = jumper_->jump();
    jump->setLength(measurer_->measure());
    jump->setStyle(judge());

    score_board_->display(
      jump->getLength(),
      competition_secretary_->calculate(jump->getLength()),
      jump->getStyle()
    );
  }

  void displayResults() {
    if (!jumper_) return;
    if (!result_row_) return;
    if (!competition_secretary_) return;

    Jump** jumps = jumper_->getJumps();

    float total_score = 0.0f;

    for (size_t i = 0; i < 2; i++) {
      Jump* jump = jumps[i];
      total_score += competition_secretary_->calculate(jump->getLength()) + jump->getStyle();
    }

    result_row_->display(jumper_->getName(), total_score);
  }

private:

  float judge() {
    float style_points_total = 0.0f;
    for (Judge* judge : judges_) {
      style_points_total += judge->judge();
    }
    return style_points_total;
  }
};
