#include "ScoreManager.h"

ScoreManager::ScoreManager() : score(0) {}

void ScoreManager::addScore(int points) {
    score += points;
}

void ScoreManager::reset() {
    score = 0;
}

int ScoreManager::getScore() const {
    return score;
}
