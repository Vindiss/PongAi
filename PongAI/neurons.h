#pragma once

struct Neurons
{
    int id;
    float weight;
    float output = 0;
    float bias = 0;
    float gradient = 0;
    float delta = 0;
};
