#include "AI.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

AI::AI(float speed, int layer, std::vector<Neurons> neurons, Barre* barre, float windowHeight)
    : speed(speed), layer(layer), neurons(neurons), barre(barre), windowHeight(windowHeight) {}

void AI::setBarre(Barre* barre) {
    this->barre = barre;
}

void AI::updateAI(Ball* ball) {
    positionBall = ball->getPosition();
    NeuralNetwork();
    MangerInput();
}

Barre* AI::getBarre() const {
    return barre;
}


void AI::NeuralNetwork() {
    for (int i = 0; i < layer; ++i) {
        for (auto& neuron : neurons) {
            neuron.weight = static_cast<float>(rand()) / RAND_MAX;
            ActivationFunction(neuron);
        }
    }
}

void AI::ActivationFunction(Neurons& neuron) {
    double sum = neuron.weight * positionBall.y + neuron.bias;
    neuron.output = Heaviside(sum);
}

void AI::MangerInput() {
    if (barre && !neurons.empty()) {
        sf::Vector2f barrePosition = barre->getShape().getPosition();
        float barreHeight = barre->getShape().getSize().y;

        if (positionBall.y < barrePosition.y) {
            if (barrePosition.y - speed >= 0) {
                barre->move(-speed); // Monte
            }
        }
        else if (positionBall.y > barrePosition.y + barreHeight) {
            if (barrePosition.y + barreHeight + speed <= windowHeight) {
                barre->move(speed); // Descend
            }
        }
    }
}


int AI::Heaviside(double x) {
    return x > 0 ? 1 : 0;
}

void AI::calculateError(float targetOutput) {
    for (auto& neuron : neurons) {
        
        float error = targetOutput - neuron.output;

        
        neuron.gradient = error * neuron.output * (1 - neuron.output);
    }
}

void AI::updateWeights(float learningRate) {
    for (auto& neuron : neurons) {
        
        neuron.delta = learningRate * neuron.gradient;
        neuron.weight += neuron.delta;

        
        neuron.bias += neuron.delta;
    }
}
