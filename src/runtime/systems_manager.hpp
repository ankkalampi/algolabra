#pragma once

#include "../systems/system.hpp"
#include "components/component_storage.hpp"
#include "entity/entity_storage.hpp"
#include "runtime/engine.hpp"
#include "systems/behavior_system.hpp"
#include "systems/coordinate_system.hpp"
#include "systems/render_system.hpp"

#include <any>
#include <memory>
#include <mutex>

using namespace systems;

namespace engine
{
struct SystemsManager : debug::Debuggable {
    CoordinateSystem coordinateSystem;
    RenderSystem renderSystem;
    BehaviorSystem behaviorSystem;

    entity::EntityStorage entityStorage;
    components::ComponentStorage componentStorage;

    uint32_t runningID = 0;
    mutable std::mutex mtx;

    SystemsManager();

    void manifest(std::vector<std::any>& components);

    uint32_t giveID();
};
}  // namespace engine