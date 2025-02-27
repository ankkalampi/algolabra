#include "runtime.hpp"

#include "../globals.hpp"
#include "../render/render.hpp"
#include "../world/world.hpp"
#include "SDL3/SDL_events.h"
#include "render/render_manager.hpp"
#include "runtime/systems_manager.hpp"
#include "systems/behavior_system.hpp"
#include "systems/coordinate_system.hpp"
#include "systems/render_system.hpp"

namespace runtime
{

Runtime::Runtime()
    : tick(0),
      coordinateSystem(systems::CoordinateSystem()),
      renderSystem(systems::RenderSystem(&coordinateSystem)),
      behaviorSystem(systems::BehaviorSystem(&coordinateSystem)),
      world(world::World(1, 1, 1, 1)),
      renderManager(renderSystem, world),
      running(true)
{
    addDebugName("RUNTIME");
    addDebugProperty("world", &world);

    addDebugProperty("coordinateSystem", &coordinateSystem);
    addDebugProperty("renderSystem", &renderSystem);
    addDebugProperty("behaviorSystem", &behaviorSystem);
    addDebugProperty("renderManager", &renderManager);
    addDebugProperty("systemsManager", &systemsManager);

    printDebugInfo();
}

void Runtime::run()

{
    // runtime loop --------------------------------------
    while (running) {
        tick++;
        // check events, quit if window closed
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        systemsManager.behaviorSystem.updateComponents();

        systemsManager.renderSystem.updateComponents();

        renderManager.update();
    }
    //------------------------------------------------------

    // cleanup of SDL stuff before exiting
    renderManager.cleanup();

    return;
}

};  // namespace runtime