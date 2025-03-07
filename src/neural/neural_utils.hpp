#pragma once

#include "cell.hpp"
#include "globals.hpp"
#include "world.hpp"
namespace neural
{
inline std::vector<world::Cell*> getSenseData(world::Cell* cell,
                                              world::World* world)
{
    int x = cell->x;
    int y = cell->y;

    std::vector<world::Cell*> sensedCells;

    // go through all cells near target cell extending 3 cells every direction.
    // Add cells that are within world, and nullptr for cells not in world
    for (int i = -3; i <= 3; ++i) {
        for (int j = -3; j <= 3; ++j) {
            // check if cell sensed if out of world boundaries, and add nullptr
            // to the vector if thi is the case
            if (y + i < 0 || y + i > CELLS_VERTICAL || x + j < 0 ||
                x + j > CELLS_HORIZONTAL) {
                sensedCells.push_back(nullptr);
            } else {
                // if cell is valid, add the cell to the vector
                sensedCells.push_back(
                    &world->cells[(y + i) * CELLS_HORIZONTAL + (x + j)]);
            }
        }
    }

    return sensedCells;
}
}  // namespace neural