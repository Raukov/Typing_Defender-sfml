#pragma once
#include "Word.h"
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(const std::string& word, float x, float y);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    bool isDefeated() const;
    Word& getWord();

private:
    Word word;
    bool defeated;
};