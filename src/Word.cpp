#include "Word.h"

Word::Word(const std::string& word, float x, float y)
    : text(word), currentInput(""), posX(x), posY(y), speed(50.0f) {}

void Word::update(float deltaTime) {
    posY += speed * deltaTime;
}

void Word::render(sf::RenderWindow& window) const {
    sf::Font font("assets/Arial.ttf");
    sf::Text wordText = sf::Text(font, "", 30);
    // Przygotuj czcionkê, kolor itd. (póŸniej do poprawy)

    wordText.setFont(font);
    wordText.setString(currentInput + "_" + text.substr(currentInput.size()));
    wordText.setPosition(sf::Vector2f(posX, posY));
    wordText.setFillColor(sf::Color::White);
    window.draw(wordText);
}

const std::string& Word::getText() const {
    return text;
}

void Word::resetInput() {
    currentInput.clear();
}

bool Word::processInput(char input) {
    if (input == text[currentInput.size()]) {
        currentInput += input;
        return true;
    }
    else {
        return false;
    }
}

bool Word::isComplete() const {
    return currentInput == text;
}