#pragma once

#include "../world/world.hpp"
#include "SDL_events.h"
#include "render/render_manager.hpp"
#include "systems/behavior_system.hpp"
#include "systems/coordinate_system.hpp"
#include "systems/render_system.hpp"

#include <optional>

namespace runtime
{

extern bool running;
extern SDL_Event event;
extern std::optional<world::World> world;
extern std::optional<world::WorldParameters> worldParameters;

struct Runtime {
    uint32_t tick;
    bool running;

    systems::CoordinateSystem coordinateSystem;
    systems::RenderSystem renderSystem;
    systems::BehaviorSystem behaviorSystem;

    render::RenderManager renderManager;

    world::World world;

    Runtime();

    void run();
};

// sets up the runtime system for simulation and rendering
void init();

// starts the runtime loop. Exits the program if window is closed
void run();

};  // namespace runtime