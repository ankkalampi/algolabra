#pragma once

#include "../runtime/debuggable.hpp"
#include "components/behavior_component.hpp"
#include "components/entity_component.hpp"
#include "components/render_component.hpp"
#include "world/cell.hpp"

#include <random>
#include <vector>

namespace engine
{
struct SystemsManager;
}

namespace entity
{
struct Habitat : public debug::Debuggable {
    std::vector<world::Cell*> cells;

    // these are for finding random cell

    std::mt19937 gen;
    std::uniform_int_distribution<size_t> distrib;

    Habitat(std::vector<world::Cell*> habitatCells);

    Habitat();

    // creating a given number of entities to the world using coordinates found
    // in free habitat cells, and path to entity file. This could fail if free
    // cell is not found fast enough
    void spawnEntity(engine::SystemsManager& systemsManager,
                     int type,

                     int num);
};
}  // namespace entity