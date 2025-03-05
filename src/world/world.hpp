#pragma once

#include "../globals.hpp"
#include "entity/habitat.hpp"
#include "population.hpp"

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

namespace entity
{
struct Carnivore;
struct Herbivore;
struct Plant;
}  // namespace entity

namespace world
{

struct World : public debug::Debuggable {
    std::vector<Cell> cells;

    entity::Habitat grassHabitat;
    entity::Habitat landHabitat;

    World(int amountWater, int amountRock, int amountSand, int amountGrass);
};

};  // namespace world
