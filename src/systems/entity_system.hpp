#pragma once

#include "../components/component.hpp"
#include "../components/entity_component.hpp"
#include "system.hpp"
#include "systems/behavior_system.hpp"
#include "systems/coordinate_system.hpp"
#include "systems/render_system.hpp"

#include <any>

namespace systems
{

// creates entity based on entity file given, and adds it to entity system
struct EntitySystem : public System<EntitySystem> {
    // these should be in a vector or something, and automatically added
    CoordinateSystem* coordinateSystem;
    RenderSystem* renderSystem;
    BehaviorSystem* behaviorSystem;

    EntitySystem(CoordinateSystem* coordinateSystem,
                 RenderSystem* renderSystem,
                 BehaviorSystem* behaviorSystem);
    // creates entity based on entity file given,
    // gives it unique id, and adds it to entity system
    // NOT IMPLEMENTED!!!! NOT IMPLEMENTED!!!! NOT IMPLEMENTED!!!!
    void manifest(std::vector<std::any> components);
};
};  // namespace systems