#pragma once

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius);
    void update();
    void bounce();
    void reverseDirection();
    sf::CircleShape getShape() const;
    sf::Vector2f getPosition() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};
