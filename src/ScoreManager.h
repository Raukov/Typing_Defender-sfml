#pragma once
#include <string>

class ScoreManager {
public:
    ScoreManager();

    void addScore(int points);
    void reset();
    int getScore() const;

private:
    int score;
};
