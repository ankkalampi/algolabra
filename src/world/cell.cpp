#include "cell.hpp"

#include "globals.hpp"
#include "world/terrain.hpp"

namespace world
{

Cell::Cell(int x, int y, terrain::Terrain type) : x(x), y(y), terrain(type)
{
    this->tenantID = 0;
    this->tenant = Tenant::Empty;
}
}  // namespace world
