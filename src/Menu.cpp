#include "Menu.h"


Menu::Menu() : title(font, ""), startOption(font, ""), scoresOption(font, ""), exitOption(font, "") {
    // Ustaw katalog roboczy na katalog Ÿród³owy
    std::filesystem::current_path("C:/Projects/SFML/Typing_Defender-sfml/src");
    // £adowanie czcionki
    if (!font.openFromFile("assets/Arial.ttf")) {
        throw std::runtime_error("Failed to load font from assets/Arial.ttf");
    }

    // Ustawienia tytu³u gry
    title.setFont(font);
    title.setString("Typing Game");
    title.setPosition(sf::Vector2f(300.0f, 100.0f));
    title.setCharacterSize(50);

    // Opcje menu
    startOption.setFont(font);
    startOption.setString("1. Start Game");
    startOption.setPosition(sf::Vector2f(300.0f, 200.0f));

    scoresOption.setFont(font);
    scoresOption.setString("2. High Scores");
    scoresOption.setPosition(sf::Vector2f(300.0f, 250.0f));

    exitOption.setFont(font);
    exitOption.setString("3. Exit");
    exitOption.setPosition(sf::Vector2f(300.0f, 300.0f));
}

void Menu::render(sf::RenderWindow& window) {
    // Rysowanie elementów menu
    window.draw(title);
    window.draw(startOption);
    window.draw(scoresOption);
    window.draw(exitOption);
}
