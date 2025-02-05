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

    
        World::World(

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
                int carnivoreBirthSatiation)
                :
                plantSpawnRate(plantSpawnRate),
                herbivoreMaturityAge(herbivoreMaturityAge),
                herbivoreBirthSatiation(herbivoreBirthSatiation),
                carnivoreMaturityAge(carnivoreMaturityAge),
                carnivoreBirthSatiation(carnivoreBirthSatiation){

            
            // reserve space for cells
            cells.reserve(CELLS_HORIZONTAL * CELLS_VERTICAL);
            plants.reserve(CELLS_HORIZONTAL * CELLS_VERTICAL);
            grassCells.reserve(CELLS_HORIZONTAL * CELLS_VERTICAL);

            // generate terrain
            generateTerrain(*this, amountWater, amountRock, amountSand, amountGrass);
            

            // populate world with starting populations
            //createStartingHerbivores(*this, numberHerbivores);
            createStartingPlants(*this, numberPlants);


        }


    // sets up simulation world. Makes it ready for starting simulation and rendering
    void setupWorld(World &world){
        // generate world for simulation
        world = World(1,1,100,1,1,1,1,1,1,1,1,1);
    }

    

    



    
    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants){

    }

};