#pragma once


#include <memory>
#include <vector>



#include <unordered_map>
#include "../globals.hpp"
#include <iostream>

#include "../entity/plant.hpp"

#include "population.hpp"


namespace entity{
    struct Carnivore;
    struct Herbivore;
    struct Plant;
}



namespace world{

   

    

    

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
        std::unordered_map<int, entity::Plant*> plants;
        std::vector<Cell*> grassCells;
        std::vector<Cell*> landCells;

        population::Population<entity::Plant> plantPopulation;
        population::Population<entity::Herbivore> herbivorePopulation;
        population::Population<entity::Carnivore> carnivorePopulation;

        int plantSpawnRate;
        int plantSpawnDistance;
        int plantMaturityAge;

        int herbivoreMaturityAge;
        int herbivoreBirthSatiation;

        int carnivoreMaturityAge;
        int carnivoreBirthSatiation;

        int runningId;
        


        World(WorldParameters parameters);




    };


    inline std::vector<entity::Plant> plants;

    // sets up simulation world. Makes it ready for starting simulation and rendering
    void setupWorld(World &world, WorldParameters parameters);

    

    

    

    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants);

};
