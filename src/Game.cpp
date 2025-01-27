#include "Game.h"

Game::Game()
    : window(sf::VideoMode({ 1920u, 1080u }), "Typing Defender"),
    isPaused(false), state(GameState::Menu) {}

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
            if (event->is<sf::Event::KeyPressed>()) {
                const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
                if (keyPressed && keyPressed->code == sf::Keyboard::Key::P)
                    isPaused = !isPaused;
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
    // Aktualizacja gry (ruch przeciwników, wpisywanie s³ów itd.)
}

void Game::render() {
    window.clear();
    if (state == GameState::Menu)
        menu.render(window);
    else if (state == GameState::Playing) {
        // Rysowanie elementów gry
    }
    window.display();
}
