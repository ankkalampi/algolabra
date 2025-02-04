#pragma once

#include <libnoise/module/perlin.h>
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


        World(

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

    inline World world = World(1,1,100,1,1,1,1,1,1,1,1,1);
    inline std::vector<entity::Animal> animals;
    inline std::vector<entity::Plant> plants;

    // sets up simulation world. Makes it ready for starting simulation and rendering
    void setupWorld();

    

    

    

    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants);

};
