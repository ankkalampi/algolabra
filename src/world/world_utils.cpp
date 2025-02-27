#include "world_utils.hpp"

#include "terrain.hpp"
#include "world.hpp"
#include "world/cell.hpp"

namespace world
{
inline int rounds = 0;
// generate terrain for a new world using perlin noise generator
void generateTerrain(World &world,
                     int amountWater,
                     int amountRock,
                     int amountSand,
                     int amountGrass)
{
    // create perlin generator
    noise::module::Perlin perlin =
        terrain::generatePerlinGenerator(PERLIN_FREQUENCY,
                                         PERLIN_PERSISTENCE,
                                         PERLIN_LACUNARITY,
                                         PERLIN_OCTAVE_COUNT);

    std::vector<Cell *> grassCells;
    std::vector<Cell *> landCells;

    // create Cells
    for (int y = 0; y < CELLS_VERTICAL; ++y) {
        for (int x = 0; x < CELLS_HORIZONTAL; ++x) {
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
            terrain::Terrain terrainType =
                terrain::determineTerrainType(noiseValue);

            world.cells.emplace_back(x, y, terrainType);

            // assign terrain to cell based on noise value
            // world.cells[cellIndex].terrain = terrainType;

            // check if cell is land or grass and add them to the appropriate
            // vector
            if (terrainType == terrain::Terrain::Sand) {
                landCells.push_back(&world.cells[cellIndex]);
            }

            if (terrainType == terrain::Terrain::Grass) {
                landCells.push_back(&world.cells[cellIndex]);
                grassCells.push_back(&world.cells[cellIndex]);
            }
        }
    }

    world.grassHabitat = entity::Habitat(grassCells);
    world.landHabitat = entity::Habitat(landCells);
}

};  // namespace world
