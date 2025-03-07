#pragma once

#include "cell.hpp"
#include "globals.hpp"
#include "terrain.hpp"
#include "world.hpp"

#include <Eigen/Dense>
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
            } else if (i == 0 && j == 0) {
                // middle cell is not included
                continue;
            } else {
                // if cell is valid, add the cell to the vector
                sensedCells.push_back(
                    &world->cells[(y + i) * CELLS_HORIZONTAL + (x + j)]);
            }
        }
    }

    return sensedCells;
}

// sigmoid activation function
template <typename T>
inline T sigmoid(T& mat)
{
    return mat.unaryExpr(
        [](float val) { return 1.0f / (1.0f + std::exp(-val)); });
}

// resolves sense data to neural net input
inline Eigen::Vector<float, 48> getInput(std::vector<world::Cell*> sensedCells)
{
    Eigen::Vector<float, 48> vec;

    for (int i = 0; i < 48; ++i) {
        float val = 0.0f;

        terrain::Terrain terrain = sensedCells[i]->terrain;
        world::Cell::Tenant tenant = sensedCells[i]->tenant;

        switch (terrain) {
        case terrain::Terrain::Water:
            break;
        case terrain::Terrain::Sand:
            val += 10;
            break;
        case terrain::Terrain::Grass:
            val += 20;
            break;
        default:
            std::cout << "NO VALID TERRAIN FOUND!!!" << std::endl;
        }

        switch (tenant) {
        case world::Cell::Tenant::Empty:
            break;
        case world::Cell::Tenant::Herbivore:
            val += 2;
            break;
        case world::Cell::Tenant::Plant:
            val += 8;
            break;
        default:
            std::cout << "NO VALID TENANT FOUND!!!" << std::endl;
        }

        vec[i] = val;
    }

    return vec;
}
}  // namespace neural