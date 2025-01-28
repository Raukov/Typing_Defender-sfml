#pragma once
#include "Word.h"
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(const std::string& word, float posX, float posY);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    bool isDefeated() const;
    Word& getWord();

	int getMaxHealth() const;
	int getCurrentHealth() const;
	void setCurrentHealth(int health);
private:
    Word word;
    float posX, posY;
    bool defeated;
    int maxHealth;
	int currentHealth;
    float speed;
};