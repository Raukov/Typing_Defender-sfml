#include "Enemy.h"
#include <string>
Enemy::Enemy(const std::string& wordText, float x, float y)
    : word(wordText), defeated(false), posX(x), posY(y){
    speed = 50;
    maxHealth = 10;
    currentHealth = maxHealth;
}

void Enemy::update(float deltaTime) {
    if (!defeated) {
        posY += deltaTime * speed;
    }
}

void Enemy::render(sf::RenderWindow& window) {
    if (!defeated) {
        word.render(window, posX, posY);

        sf::Font font("assets/Arial.ttf");
        sf::Text wordText = sf::Text(font, "", 30);
        // Przygotuj czcionkê, kolor itd. (póŸniej do poprawy)

        wordText.setFont(font);
        wordText.setString(std::to_string(getCurrentHealth()) + "/" + std::to_string(getMaxHealth()));
        wordText.setPosition(sf::Vector2f(posX, posY - 32));
        wordText.setFillColor(sf::Color::White);
        window.draw(wordText);
    }
}

bool Enemy::isDefeated() const {
    return defeated;
}

Word& Enemy::getWord() {
    return word;
}
int Enemy::getMaxHealth() const {
	return maxHealth;
}
int Enemy::getCurrentHealth() const {
	return currentHealth;
}
void Enemy::setCurrentHealth(int health) {
	if (health <= 0) {
		defeated = true;
        return;
	}
    currentHealth = health;
}