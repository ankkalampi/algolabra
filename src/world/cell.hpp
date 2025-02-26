#pragma once
#include "terrain.hpp"

namespace world
{
struct Cell {
    terrain::Terrain terrain;
    enum Tenant { Empty, Herbivore, Predator } tenant;
    int tenantID;
    int x, y;

    // translates a coordinate component from Cell coordinates to pixel
    // coordinates
    // NOT IMPLEMENTED YET!!! NOT IMPLEMENTED YET!!! NOT IMPLEMENTED YET!!!
    static int translateCoordinate(int coordinate);

    Cell(int x, int y, terrain::Terrain type);
};
}  // namespace world
