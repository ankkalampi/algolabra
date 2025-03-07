#pragma once

#include "systems_manager.hpp"

#include <cstdint>
namespace entity
{

void createPlant(engine::SystemsManager& sysManager, world::Cell* cell);

void createHerbivore(engine::SystemsManager& sysManager, world::Cell* cell);

}  // namespace entity