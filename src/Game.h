#pragma once
#include "Menu.h"
#include <SFML/Graphics.hpp>
class Game {
public:
    Game();
    void run();

    // Umo�liwienie dost�pu do GameState poza klas�
    enum class GameState { Menu, Playing, GameOver };

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    Menu menu;
    bool isPaused;
    GameState state; 
};
