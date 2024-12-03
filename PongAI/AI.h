#pragma once

#include "Barre.h"
#include "SFML/Graphics.hpp"
#include "Neurons.h"
#include "Ball.h"
#include <vector>

class AI {
public:
    AI(float speed, int layer, std::vector<Neurons> neurons, Barre* barre, float windowHeight);
    void setBarre(Barre* barre);
    void updateAI(Ball* ball);
    Barre* getBarre() const;

private:
    void NeuralNetwork();
    void ActivationFunction(Neurons& neuron);
    void MangerInput();
    int Heaviside(double x);
    void calculateError(float targetOutput);
    void updateWeights(float learningRate);

    Barre* barre;
    float speed;
    int layer;
    float windowHeight;
    std::vector<Neurons> neurons;
    sf::Vector2f positionBall;
    float targetOutput;
};
