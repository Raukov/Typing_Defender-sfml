#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h" 

class Menu {
public:
    Menu();

    void handleInput(const sf::Keyboard::Scancode keyPressed, Game::GameState& state);
    void render(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text title;
    sf::Text startOption;
    sf::Text scoresOption;
    sf::Text exitOption;
};
