#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();

    void render(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text title;
    sf::Text startOption;
    sf::Text scoresOption;
    sf::Text exitOption;
};
