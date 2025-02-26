#pragma once

#include "world.hpp"

#include <algorithm>
#include <random>

namespace world
{

struct World;

// generate terrain for a new world using perlin noise generator
void generateTerrain(World& world,
                     int amountWater,
                     int amountRock,
                     int amountSand,
                     int amountGrass);

// helper function for shuffling vectors
template <typename T>
void shuffleVector(std::vector<T>& vec)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(vec.begin(), vec.end(), gen);
}

};  // namespace world
