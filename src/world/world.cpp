#include <libnoise/module/perlin.h>
#include <vector>
#include <unordered_map>
#include "../globals.hpp"
#include <iostream>
#include "world.hpp"
#include "entity.hpp"

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

    

    // creates perlin generator to use with terrain generation
    noise::module::Perlin generatePerlinGnerator(double freq, double pers, double lacun, double octave){
        noise::module::Perlin perlin;

        perlin.SetFrequency(freq);
        perlin.SetPersistence(pers);
        perlin.SetLacunarity(lacun);
        perlin.SetOctaveCount(octave);

        return perlin;
    }

    // determine terrain type baswd on treshold values in perlin terrain generation
    Terrain determineTerrainType(float value){
        if (value < GRASS_TRESHOLD){
            return Terrain::Water;
        } else if (value < WATER_TRESHOLD){
            return Terrain::Sand;
        } else if (value < SAND_TRESHOLD){
            return Terrain::Sand;
        } else{
            return Terrain::Grass;
        }
    }



    // generate terrain for a new world using perlin noise generator
    void generateTerrain(
                            World& world,
                            int amountWater,
                            int amountRock,
                            int amountSand,
                            int amountGrass){

        // create perlin generator
        noise::module::Perlin perlin = generatePerlinGnerator(
                                                                PERLIN_FREQUENCY,
                                                                PERLIN_PERSISTENCE,
                                                                PERLIN_LACUNARITY,
                                                                PERLIN_OCTAVE_COUNT);



        // create Cells
        for(int y = 0; y < CELLS_VERTICAL; ++y){
            for(int x = 0; x < CELLS_HORIZONTAL; ++x){
                world.cells.emplace_back(x, y);

                // scale coordinates for perlin
                double nx = x * PERLIN_SCALE;
                double ny = y * PERLIN_SCALE;

                // get noise value between -1, 1
                float noiseValue = perlin.GetValue(nx, ny, 0.0);

                // transform value to be between 0,1
                noiseValue = (noiseValue + 1.0f) / 2.0f;

                // assign terrain to cell based on noise value
                //std::cout << "accessing cell num: " << (y * CELLS_HORIZONTAL +x) << " cells total: " << world.cells.size() << " width: " << CELLS_HORIZONTAL << " height: " << CELLS_VERTICAL << " determining type for cell: " << x << ", " << y << std::endl;
                world.cells[y * CELLS_HORIZONTAL + x].terrain = determineTerrainType(noiseValue);

            }
        }


    }

    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants){

    }

};