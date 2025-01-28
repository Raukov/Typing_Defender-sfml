#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Word {
public:
    Word(const std::string& word);

    void render(sf::RenderWindow& window, float x, float y) const;

    const std::string& getText() const;
    void resetInput();
    bool processInput(char input);
    bool isComplete() const;

private:
    std::string text;
    std::string currentInput;

    sf::Font font;
    sf::Text wordText;
};