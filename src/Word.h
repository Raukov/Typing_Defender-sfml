#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Word {
public:
    Word(const std::string& word, float x, float y);

    void update(float deltaTime);
    void render(sf::RenderWindow& window) const;

    const std::string& getText() const;
    void resetInput();
    bool processInput(char input);
    bool isComplete() const;

private:
    std::string text;
    std::string currentInput;
    float posX, posY;
    float speed;
};