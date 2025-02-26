#pragma once

#include "components/behavior_component.hpp"
#include "components/entity_component.hpp"
#include "components/render_component.hpp"
#include "runtime/systems_manager.hpp"
#include "systems/entity_system.hpp"
#include "world/cell.hpp"

#include <random>
#include <vector>
namespace entity
{
struct Habitat {
    std::vector<world::Cell*> cells;

    // these are for finding random cell

    std::mt19937 gen;
    std::uniform_int_distribution<size_t> distrib;

    Habitat(std::vector<world::Cell*>& habitatCells);

    Habitat();

    // creating a given number of entities to the world using coordinates found
    // in free habitat cells, and path to entity file. This could fail if free
    // cell is not found fast enough
    void spawnEntity(engine::SystemsManager& SystemsManager,
                     const std::vector<std::any>& components,
                     int num);
};
}  // namespace entity