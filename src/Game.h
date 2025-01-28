#pragma once
#include "Menu.h"
#include "Player.h"
#include "Enemy.h"
#include "ScoreManager.h"

#include <SFML/Graphics.hpp>
class Game {
public:
    Game();
    void run();

    // Umo¿liwienie dostêpu do GameState poza klas¹
    enum class GameState { Menu, Playing, GameOver };

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void SpawnEnemies();
    void render();

    sf::RenderWindow window;
    Menu menu;
    bool isPaused;
    GameState state; 

    Player player;
    ScoreManager scoreManager;
    std::vector<Enemy> enemies; // Lista przeciwników
    sf::Clock spawnClock;
};
