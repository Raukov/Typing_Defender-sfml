#include "Enemy.h"

Enemy::Enemy(const std::string& wordText, float x, float y)
    : word(wordText, x, y), defeated(false) {}

void Enemy::update(float deltaTime) {
    if (!defeated)
        word.update(deltaTime);
}

void Enemy::render(sf::RenderWindow& window) {
    if (!defeated)
        word.render(window);
}

bool Enemy::isDefeated() const {
    return defeated;
}

Word& Enemy::getWord() {
    return word;
}