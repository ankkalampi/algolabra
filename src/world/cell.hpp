#pragma once
#include "globals.hpp"
#include "terrain.hpp"

namespace world
{
struct Cell {
    terrain::Terrain terrain;
    enum Tenant { Empty, Herbivore, Predator, Plant } tenant;
    int tenantID;
    int x, y;

    // translates a coordinate component from Cell coordinates to pixel
    // coordinates
    inline static int translateCoordinate(int coordinate)
    {
        return coordinate * CELL_SIZE;
    }

    Cell(int x, int y, terrain::Terrain type);
};
}  // namespace world
