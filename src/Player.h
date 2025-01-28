#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(float x, float y);

    void render(sf::RenderWindow& window) const;
    void setAnimation(bool active);

private:
    sf::RectangleShape shape;
    bool isAttacking; // Flaga do animacji ataku
};
