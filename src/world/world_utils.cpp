#include "world_utils.hpp"
#include "world.hpp"
#include "terrain.hpp"
#include "../entity/plant.hpp"




namespace world{
    inline int rounds = 0;
    // generate terrain for a new world using perlin noise generator
    void generateTerrain(
                            World& world,
                            int amountWater,
                            int amountRock,
                            int amountSand,
                            int amountGrass){

        // create perlin generator
        noise::module::Perlin perlin = terrain::generatePerlinGenerator(
                                                                PERLIN_FREQUENCY,
                                                                PERLIN_PERSISTENCE,
                                                                PERLIN_LACUNARITY,
                                                                PERLIN_OCTAVE_COUNT);



        // create Cells
        for(int y = 0; y < CELLS_VERTICAL; ++y){
            for(int x = 0; x < CELLS_HORIZONTAL; ++x){
                world.cells.emplace_back(x, y);

                // calculate cell index
                int cellIndex = y * CELLS_HORIZONTAL + x;

                // scale coordinates for perlin
                double nx = x * PERLIN_SCALE;
                double ny = y * PERLIN_SCALE;

                // get noise value between -1, 1
                float noiseValue = perlin.GetValue(nx, ny, 0.0);

                // transform value to be between 0,1
                noiseValue = (noiseValue + 1.0f) / 2.0f;

                // get terrain type based on noise value
                terrain::Terrain terrainType = terrain::determineTerrainType(noiseValue);

                // assign terrain to cell based on noise value
                world.cells[cellIndex].terrain = terrainType;

               
                // check if cell is land or grass and add them to the appropriate vector
                if (terrainType == terrain::Terrain::Sand) {
                    world.landCells.push_back(&world.cells[cellIndex]);
                }

                if (terrainType == terrain::Grass) {
                    world.landCells.push_back(&world.cells[cellIndex]);
                    world.grassCells.push_back(&world.cells[cellIndex]);
                }

                

                

            }
        }


    }

    


    // create starting population of plants in the world
    void createStartingPlants(World &world, int numberPlants){
        //std::cout << "Creating starting population of plants..." << std::endl;

        // shuffle vector to randomize order of cells
        shuffleVector(world.grassCells);

        
        for (int i = 0; i < numberPlants; ++i) {

            // get real cell index of a cell in shuffled grassCells vector
            int x = world.grassCells[i]->x;
            int y = world.grassCells[i]->y;
            int cellIndex = x + y * CELLS_HORIZONTAL;

           // add plant to the map containing plants and their cell indices
            world.plants.insert({cellIndex, new entity::Plant(world.runningId, 20, 20)});
            world.runningId++;
            //std::cout << "creating new plant in cell: x: " << x << ", y: " << y << ", cellIndex: " << cellIndex << std::endl;
            //std::cout << "size of plants map: " << world.plants.size() << std::endl;
            rounds++;
        }

        //std::cout << "size of plants map: " << world.plants.size() << std::endl;
        //std::cout << "rounds: " << rounds << " numberPlants: " << numberPlants << std::endl;
        return;
    }

    // create starting population of animals in the world
    void createStartingHerbivores(World &world, int numberHerbivores){

        // shuffle vector to randomize order of cells
        shuffleVector(world.landCells);

    }


};

