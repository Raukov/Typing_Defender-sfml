#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class Game {
public:
    Game();
    void run();

    // Umo¿liwienie dostêpu do GameState poza klas¹
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
