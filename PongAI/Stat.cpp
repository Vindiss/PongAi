#include "Stat.h"

Stat::Stat() : score(0) {}

void Stat::incrementScore() {
    score++;
}

int Stat::getScore() const {
    return score;
}

sf::Text Stat::getScoreText(const sf::Font& font) const {
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + std::to_string(score));
    text.setCharacterSize(30); 
    text.setFillColor(sf::Color::White);
    return text;
}
