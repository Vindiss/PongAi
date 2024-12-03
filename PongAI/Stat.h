#pragma once

#include <SFML/Graphics.hpp>

class Stat {
public:
    Stat();
    void incrementScore();
    int getScore() const;
    sf::Text getScoreText(const sf::Font& font) const;

private:
    int score;
};