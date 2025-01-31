#pragma once

#include <libnoise/module/perlin.h>
#include <vector>
#include <unordered_map>
#include "../globals.hpp"
#include <iostream>
#include "entity.hpp"

namespace world{

   

    enum Terrain {
        Grass,
        Sand,
        Water,
        Rock,
        NotSet
    };

    struct Cell{
        Terrain terrain;
        enum Tenant {Empty, Herbivore, Predator} tenant;
        int tenantID;
        int x, y;

        Cell(int x, int y);
    };

    struct World{
        std::vector<Cell> cells;
        std::unordered_map<int, entity::Animal*> animals;
        std::unordered_map<int, entity::Plant*> plants;

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

    inline World world = World(1,1,1,1,1,1,1,1,1,1,1,1);
    inline std::vector<entity::Animal> animals;
    inline std::vector<entity::Plant> plants;

    // sets up simulation world. Makes it ready for starting simulation and rendering
    void setupWorld();

    

    // creates perlin generator to use with terrain generation
    noise::module::Perlin generatePerlinGnerator(double freq, double pers, double lacun, double octave);

    // determine terrain type baswd on treshold values in perlin terrain generation
    Terrain determineTerrainType(float value);



    // generate terrain for a new world using perlin noise generator
    void generateTerrain(
                            World& world,
                            int amountWater,
                            int amountRock,
                            int amountSand,
                            int amountGrass);

    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants);

};
