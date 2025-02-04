#include "world_utils.hpp"


namespace world{
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

                // scale coordinates for perlin
                double nx = x * PERLIN_SCALE;
                double ny = y * PERLIN_SCALE;

                // get noise value between -1, 1
                float noiseValue = perlin.GetValue(nx, ny, 0.0);

                // transform value to be between 0,1
                noiseValue = (noiseValue + 1.0f) / 2.0f;

                // assign terrain to cell based on noise value
                //std::cout << "accessing cell num: " << (y * CELLS_HORIZONTAL +x) << " cells total: " << world.cells.size() << " width: " << CELLS_HORIZONTAL << " height: " << CELLS_VERTICAL << " determining type for cell: " << x << ", " << y << std::endl;
                world.cells[y * CELLS_HORIZONTAL + x].terrain = terrain::determineTerrainType(noiseValue);

            }
        }


    }
};

