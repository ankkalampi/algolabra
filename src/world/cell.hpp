#pragma once
#include "terrain.hpp"



namespace world{
    struct Cell{
        terrain::Terrain terrain;
        enum Tenant {Empty, Herbivore, Predator} tenant;
        int tenantID;
        int x, y;
    
        Cell(int x, int y);
    };
}
