#include "runtime.hpp"

#include "../globals.hpp"
#include "../render/render.hpp"
#include "../world/world.hpp"
#include "SDL3/SDL_events.h"
#include "render/render_manager.hpp"
#include "runtime/systems_manager.hpp"
#include "systems/behavior_system.hpp"
#include "systems/coordinate_system.hpp"
#include "systems/entity_system.hpp"
#include "systems/render_system.hpp"

namespace runtime
{

Runtime::Runtime()
    : tick(0),
      coordinateSystem(systems::CoordinateSystem()),
      renderSystem(systems::RenderSystem(&coordinateSystem)),
      behaviorSystem(systems::BehaviorSystem(&coordinateSystem)),
      entitySystem(&coordinateSystem, &renderSystem, &behaviorSystem),
      world(world::World(1, 1, 1, 1)),
      renderManager(renderSystem, world),
      running(true)
{
    std::cout << "we are constructing runtime!" << std::endl;
    std::cout << "----------------------RUNTIME PROPERTIES--------------------"
              << std::endl;
    std::cout << "coordinatesystem: " << &coordinateSystem << std::endl;
    std::cout << "rendersystem: " << &renderSystem << std::endl;
    std::cout << "behaviorsystem: " << &behaviorSystem << std::endl;
    std::cout << "world: " << &world << std::endl;
    std::cout << "rendermanager: " << &renderManager << std::endl;
    std::cout << "----------------------RUNTIME PROPERTIES--------------------"
              << std::endl;
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

        std::cout << "int the runtime loop, about to update behaviorsystem"
                  << std::endl;
        systemsManager.behaviorSystem.updateComponents();
        std::cout << "int the runtime loop, behaviorsystem updated, about to "
                     "update rendersystem"
                  << std::endl;
        systemsManager.renderSystem.updateComponents();
        std::cout << "int the runtime loop, rendersystem updated, about to "
                     "update rendermanager"
                  << std::endl;
        renderManager.update();
        std::cout << "int the runtime loop, rendermanager updated" << std::endl;
    }
    //------------------------------------------------------

    // cleanup of SDL stuff before exiting
    renderManager.cleanup();

    return;
}

};  // namespace runtime