#include "Game.h"
#include <iostream>

Game::Game()
    : window(sf::VideoMode::getDesktopMode(), "Pong Game", sf::Style::Fullscreen),
    ball(10.f),
    barre(10.f, 100.f),
    playerControl(barre, window),
    ai(0.1f, 1, { Neurons{0, 0.5f} }, & barre, window.getSize().y) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erreur lors du chargement de la police" << std::endl;
    }
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
    }

    playerControl.handleInput();  
}

void Game::update() {
    ball.update();  
    ai.updateAI(&ball);  

    checkCollisions();
}

void Game::render() {
    window.clear();
    window.draw(ball.getShape());
    window.draw(barre.getShape());
    window.draw(stat.getScoreText(font));

    window.display();
}

void Game::checkCollisions() {
    
    if (ball.getShape().getPosition().y <= 0 ||
        ball.getShape().getPosition().y >= window.getSize().y - ball.getShape().getRadius() * 2 ) {
        ball.bounce();
    }
    if (ball.getShape().getPosition().x >= window.getSize().x)
    {
        ball.reverseDirection();
    }
        

    
    if (ball.getShape().getGlobalBounds().intersects(ai.getBarre()->getShape().getGlobalBounds())) {
        ball.reverseDirection();
    }

  
    if (ball.getShape().getPosition().x <= 0) {
        ball = Ball(10.f);
        stat.incrementScore();
    }
}

