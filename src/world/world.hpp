#pragma once

#include "noise/module/perlin.h"

#include <memory>
#include <vector>



#include <unordered_map>
#include "../globals.hpp"
#include <iostream>
#include "../entity/animal.hpp"
#include "../entity/plant.hpp"
#include "terrain.hpp"



namespace world{

   

    

    struct Cell{
        terrain::Terrain terrain;
        enum Tenant {Empty, Herbivore, Predator} tenant;
        int tenantID;
        int x, y;

        Cell(int x, int y);
    };

    struct WorldParameters{
        int numberHerbivores;
        int numberCarnivores;
        int numberPlants;
        int amountGrass;
        int amountRock;
        int amountSand;
        int amountWater;
        int plantSpawnRate;
        int herbivoreMaturityAge;
        int herbivoreBirthSatiation;
        int carnivoreMaturityAge;
        int carnivoreBirthSatiation;

        WorldParameters(

                int numberHerbivores,
                int numberCarnivores,
                int numberPlants,
                int amountGrass,
                int amountRock,
                int amountSand,
                int amountWater,
                int plantSpawnRate,
                int herbivoreMaturityAge,
                int herbivoreBirthSatiation,
                int carnivoreMaturityAge,
                int carnivoreBirthSatiation);
    };



    struct World{
        std::vector<Cell> cells;
        std::unordered_map<int, entity::Animal*> animals;
        std::unordered_map<int, entity::Plant*> plants;
        std::vector<Cell*> grassCells;
        std::vector<Cell*> landCells;

        int plantSpawnRate;
        int plantSpawnDistance;
        int plantMaturityAge;

        int herbivoreMaturityAge;
        int herbivoreBirthSatiation;

        int carnivoreMaturityAge;
        int carnivoreBirthSatiation;


        World(WorldParameters parameters);




    };


    inline std::vector<entity::Animal> animals;
    inline std::vector<entity::Plant> plants;

    // sets up simulation world. Makes it ready for starting simulation and rendering
    void setupWorld(World &world, WorldParameters parameters);

    

    

    

    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants);

};
