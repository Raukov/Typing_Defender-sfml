#include "Player.h"

Player::Player(float x, float y) : isAttacking(false) {
    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setPosition(sf::Vector2f(x,y));
    shape.setFillColor(sf::Color::Blue);
}

void Player::render(sf::RenderWindow& window) const {
    window.draw(shape);
}

void Player::setAnimation(bool active) {
    isAttacking = active;
    if (isAttacking) {
        shape.setFillColor(sf::Color::Red); // Prosty efekt animacji
    }
    else {
        shape.setFillColor(sf::Color::Blue);
    }
}
