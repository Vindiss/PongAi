#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Barre.h"
#include "PlayerControl.h"
#include "Stat.h"
#include "AI.h"

class Game {
public:
    Game();

    void run();

private:
    void processEvents();
    void update();
    void render();
    void checkCollisions();

    sf::RenderWindow window;
    Ball ball;
    Barre barre;
    PlayerControl playerControl;
    Stat stat;
    AI ai;
    sf::Font font;
};
