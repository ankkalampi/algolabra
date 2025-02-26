#include "cell.hpp"

#include "world/terrain.hpp"

namespace world
{

// translates a coordinate component from Cell coordinates to pixel
// coordinates
int Cell::translateCoordinate(int coordinate) { return coordinate; }

Cell::Cell(int x, int y, terrain::Terrain type) : x(x), y(y), terrain(type)
{
    this->tenantID = 0;
    this->tenant = Tenant::Empty;
}
}  // namespace world
