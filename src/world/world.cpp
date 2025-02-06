#include <libnoise/module/perlin.h>
#include <vector>
#include <unordered_map>
#include "../globals.hpp"
#include <iostream>
#include "world.hpp"

#include "world_utils.hpp"
#include "terrain.hpp"

namespace world{

   



        Cell::Cell(int x, int y) : x(x), y(y){
            this->tenantID = 0;
            this->tenant = Tenant::Empty;
        }

        WorldParameters::WorldParameters(

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
                int carnivoreBirthSatiation) :
                numberHerbivores(numberHerbivores),
                numberCarnivores(numberCarnivores),
                numberPlants(numberPlants),
                amountGrass(amountGrass),
                amountRock(amountRock),
                amountSand(amountSand),
                amountWater(amountWater),
                plantSpawnRate(plantSpawnRate),
                herbivoreMaturityAge(herbivoreMaturityAge),
                herbivoreBirthSatiation(herbivoreBirthSatiation),
                carnivoreMaturityAge(carnivoreMaturityAge),
                carnivoreBirthSatiation(carnivoreBirthSatiation)
                {}

    
        World::World(

                WorldParameters parameters)
                :
                plantSpawnRate(parameters.plantSpawnRate),
                herbivoreMaturityAge(parameters.herbivoreMaturityAge),
                herbivoreBirthSatiation(parameters.herbivoreBirthSatiation),
                carnivoreMaturityAge(parameters.carnivoreMaturityAge),
                carnivoreBirthSatiation(parameters.carnivoreBirthSatiation){

            
            // reserve space for cells
            cells.reserve(CELLS_HORIZONTAL * CELLS_VERTICAL);
            plants.reserve(CELLS_HORIZONTAL * CELLS_VERTICAL);
            grassCells.reserve(CELLS_HORIZONTAL * CELLS_VERTICAL);

            // generate terrain
            generateTerrain(*this, parameters.amountWater, parameters.amountRock, parameters.amountSand, parameters.amountGrass);
            

            // populate world with starting populations
            //createStartingHerbivores(*this, numberHerbivores);
            createStartingPlants(*this, parameters.numberPlants);


        }


    // sets up simulation world. Makes it ready for starting simulation and rendering
    void setupWorld(World &world, WorldParameters parameters){
        // generate world for simulation
        world = World(parameters);
    }

    

    



    
    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants){

    }

};