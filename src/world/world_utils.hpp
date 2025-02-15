#pragma once



#include "world.hpp"
#include <random>
#include <algorithm>



namespace world{

    struct World;

    // generate terrain for a new world using perlin noise generator
    void generateTerrain(
                        World& world,
                        int amountWater,
                        int amountRock,
                        int amountSand,
                        int amountGrass);


    // create starting population of plants in the world
    void createStartingPlants(World &world, int numberPlants);

    // create starting population of animals in the world
    void createStartingHerbivores(World &world, int numberHerbivores);

    // helper function for shuffling vectors
    template <typename T>
    void shuffleVector(std::vector<T>& vec){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(vec.begin(), vec.end(), gen);
    }


};

