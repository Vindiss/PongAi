#include "Barre.h"

Barre::Barre(float width, float height) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    shape.setPosition(50, 250);
}

void Barre::move(float offset) {
    shape.move(0, offset);
}

sf::RectangleShape Barre::getShape() const {
    return shape;
}
