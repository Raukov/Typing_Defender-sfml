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
        if (event->is<sf::Event::Closed>())
            window.close();

        else if(state == GameState::Menu) 
        {
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();

                menu.handleInput(keyPressed->scancode, state);
            }
        }
        else if (state == GameState::Playing && event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::P)
            isPaused = !isPaused;

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
