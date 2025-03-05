#pragma once

#include "systems_manager.hpp"

#include <cstdint>
namespace entity
{

void createPlant(engine::SystemsManager& sysManager, int x, int y);

void createHerbivore(engine::SystemsManager& sysManager, int x, int y);

}  // namespace entity