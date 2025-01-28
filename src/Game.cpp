#include "Game.h"
#include <iostream>
Game::Game()
    : window(sf::VideoMode({ 1920u, 1080u }), "Typing Defender"),
    isPaused(false), state(GameState::Menu), player(960.0f, 900.0f) {
}


void Game::run() {
    sf::Clock clock;
    window.setFramerateLimit(144);
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        if (state == GameState::Playing && !isPaused)
            update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
            continue;
        }
        switch (state) {
        case GameState::Menu: {
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyPressed->scancode) {
                case sf::Keyboard::Scancode::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Scancode::Num1:
                    state = GameState::Playing;
                    break;
                case sf::Keyboard::Scancode::Num3:
                    exit(0);
                    break;
                default:
                    break;
                }
            }
            break;
        }
        case GameState::Playing: {
            if (event->is<sf::Event::TextEntered>()) {
                char input = static_cast<char>(event->getIf<sf::Event::TextEntered>()->unicode);
                for (auto& enemy : enemies) {
                    if (enemy.getWord().processInput(input)) {
                        if (enemy.getWord().isComplete()) {
							enemy.setCurrentHealth(enemy.getCurrentHealth() - 5);
							if (enemy.isDefeated()) {
								enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& enemy) {
									return enemy.isDefeated();
									}), enemies.end());
								std::cout << "enemy defeated" << std::endl;
							}
							std::cout << enemies.size() << std::endl;
                            player.setAnimation(true); // Animacja ataku
                        }
                        break; // Obs³u¿ jedno s³owo na raz
                    }
                }
            }
            break;
        }
        case GameState::GameOver: {
            // Obs³uga stanu GameOver 
            break;
        }
        default:
            break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    SpawnEnemies();
    for (auto& enemy : enemies) {
        enemy.update(deltaTime.asSeconds());
        if (enemy.getWord().isComplete()) {
            // Przeciwnik pokonany?
            scoreManager.addScore(10);
            enemy.getWord().resetInput();
        }
    }
}

void Game::SpawnEnemies() {
	// Dodaj nowego przeciwnika co 2 sekund
	if (spawnClock.getElapsedTime().asSeconds() > 2.0f) {
		enemies.emplace_back("sword", 500.0f, 0.0f);
		spawnClock.restart();
	}
}
void Game::render() {
    window.clear();
    if (state == GameState::Menu) {
        menu.render(window);
    }
    else if (state == GameState::Playing) {
        player.render(window);
        for (Enemy& enemy : enemies) { 
            enemy.render(window);
        }
    }
    window.display();
}

