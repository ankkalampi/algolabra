#pragma once

#include <libnoise/module/perlin.h>
#include <vector>
#include <unordered_map>
#include "../globals.hpp"
#include <iostream>

namespace world{

   

    // forward declarations
    struct Animal;
    struct Plant;
    struct World;

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
    ////////////////////////

    

    



    

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

        Cell(int x, int y) : x(x), y(y){
            this->tenantID = 0;
            this->tenant = Tenant::Empty;
        }
    };

    struct World{
        std::vector<Cell> cells;
        std::unordered_map<int, Animal*> animals;
        std::unordered_map<int, Plant*> plants;

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


    };

    inline World world = World(1,1,1,1,1,1,1,1,1,1,1,1);
    extern std::vector<Animal> animals;
    extern std::vector<Plant> plants;

    // sets up simulation world. Makes it ready for starting simulation and rendering
    inline void setupWorld(){
        // generate world for simulation
        world::world = World(1,1,1,1,1,1,1,1,1,1,1,1);
    }

    

    // creates perlin generator to use with terrain generation
    inline noise::module::Perlin generatePerlinGnerator(double freq, double pers, double lacun, double octave){
        noise::module::Perlin perlin;

        perlin.SetFrequency(freq);
        perlin.SetPersistence(pers);
        perlin.SetLacunarity(lacun);
        perlin.SetOctaveCount(octave);

        return perlin;
    }

    // determine terrain type baswd on treshold values in perlin terrain generation
    inline Terrain determineTerrainType(float value){
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
    inline void generateTerrain(
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

    inline void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants){

    }

};
