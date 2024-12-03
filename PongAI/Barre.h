#pragma once

#include <SFML/Graphics.hpp>

class Barre {
public:
    Barre(float width, float height);
    void move(float offset);
    sf::RectangleShape getShape() const;

private:
    sf::RectangleShape shape;
};

