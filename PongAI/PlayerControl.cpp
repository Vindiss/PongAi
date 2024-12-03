#include "PlayerControl.h"
#include <SFML/Window.hpp>

PlayerControl::PlayerControl(Barre& barre, const sf::RenderWindow& window) : barre(barre), window(window) {}

void PlayerControl::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        barre.move(-0.1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        barre.move(0.1);
    }


    if (barre.getShape().getPosition().y < 0) {
        barre.move(0.1); 
    }
    if (barre.getShape().getPosition().y + barre.getShape().getSize().y > window.getSize().y) {
        barre.move(-0.1); 
    }
}
