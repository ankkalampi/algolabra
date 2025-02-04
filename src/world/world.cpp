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



            // generate terrain and starting populations
            generateTerrain(*this, amountWater, amountRock, amountSand, amountGrass);
            populateWorld(*this, numberHerbivores, numberCarnivores, numberPlants);



        }


    // sets up simulation world. Makes it ready for starting simulation and rendering
    void setupWorld(){
        // generate world for simulation
        world::world = World(1,1,1,1,1,1,1,1,1,1,1,1);
    }

    

    



    
    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants){

    }

};