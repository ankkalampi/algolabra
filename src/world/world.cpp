
#include "world.hpp"

#include "../globals.hpp"
#include "entity/habitat.hpp"
#include "world/population.hpp"
#include "world_utils.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>

namespace world
{

World::World(int amountWater, int amountRock, int amountSand, int amountGrass)

{
    // reserve space for cells
    cells.reserve(CELLS_HORIZONTAL * CELLS_VERTICAL + 10);

    // generate terrain
    generateTerrain(*this, amountWater, amountRock, amountSand, amountGrass);

    addDebugName("WORLD");
    addDebugProperty("cells", &cells);
    addDebugProperty("grassHabitat", &grassHabitat);
    addDebugProperty("landHabitat", &landHabitat);
}

};  // namespace world