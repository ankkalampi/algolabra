
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
    cells.reserve(CELLS_HORIZONTAL * CELLS_VERTICAL);

    std::cout << "just about to generate terrain!!!" << std::endl;

    // generate terrain
    generateTerrain(*this, amountWater, amountRock, amountSand, amountGrass);

    std::cout << "--------------WORLD------------------" << std::endl;
    std::cout << "world created! habitats: " << std::endl;
    std::cout << "grasshabitat: " << &grassHabitat << std::endl;
    std::cout << "landhabitat: " << &landHabitat << std::endl;
    std::cout << "--------------WORLD------------------" << std::endl;
}

};  // namespace world