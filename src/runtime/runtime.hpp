#pragma once

#include "../world/world.hpp"
#include "SDL3/SDL_events.h"
#include "components/entity_component.hpp"
#include "components/render_component.hpp"
#include "render/render_manager.hpp"
#include "runtime/engine.hpp"
#include "runtime/systems_manager.hpp"
#include "systems/behavior_system.hpp"
#include "systems/coordinate_system.hpp"
#include "systems/render_system.hpp"

#include <optional>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <variant>

// this system stuff should maybe go to dedicated system manager class
// better yet, this std::variant and system pointer map stuff should be
// automatically handled using some static magic in component and system

namespace runtime
{

struct Runtime : public debug::Debuggable {
    uint32_t tick;
    bool running;

    SDL_Event event;

    // this system stuff should maybe go to dedicated system manager class
    // better yet, this std::variant and system pointer map stuff should be
    // automatically handled using some static magic in component and system

    world::World world;

    systems::CoordinateSystem coordinateSystem;
    systems::RenderSystem renderSystem;
    systems::BehaviorSystem behaviorSystem;
    // end of systems stuff

    render::RenderManager renderManager;
    engine::SystemsManager systemsManager = engine::SystemsManager();

    Runtime();

    void run();
};

};  // namespace runtime