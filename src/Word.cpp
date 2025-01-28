#include "Word.h"

Word::Word(const std::string& word)
    : text(word), currentInput(""), wordText(font, ""){}



void Word::render(sf::RenderWindow& window, float x, float y) const {
    sf::Font font("assets/Arial.ttf");
    sf::Text wordText = sf::Text(font, "", 30);
    // Przygotuj czcionkê, kolor itd. (póŸniej do poprawy)

    wordText.setFont(font);
    wordText.setString(currentInput + "_" + text.substr(currentInput.size()));
    wordText.setPosition(sf::Vector2f(x, y));
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
        currentInput += input; // Dodanie poprawnie wpisanego znaku
        return true;
    }
    return false; // Niepoprawny znak
}

bool Word::isComplete() const {
    return currentInput == text;
}