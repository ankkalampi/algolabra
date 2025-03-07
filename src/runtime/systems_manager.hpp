#pragma once

#include "../systems/system.hpp"
#include "systems/behavior_system.hpp"
#include "systems/coordinate_system.hpp"
#include "systems/render_system.hpp"
#include "world.hpp"

#include <any>
#include <memory>
#include <mutex>

namespace engine
{
struct SystemsManager : debug::Debuggable {
    world::World world;

    systems::CoordinateSystem coordinateSystem;
    systems::RenderSystem renderSystem;
    systems::BehaviorSystem behaviorSystem;

    uint32_t runningID = 0;
    mutable std::mutex mtx;

    SystemsManager();

    void manifest(std::vector<std::any>& components);

    uint32_t giveID();
};
}  // namespace engine