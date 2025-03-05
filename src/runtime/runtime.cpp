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

      systemsManager(engine::SystemsManager()),
      renderManager(systemsManager.renderSystem, systemsManager.world),
      running(true)
{
    addDebugName("RUNTIME");

    addDebugProperty("renderManager", &renderManager);
    addDebugProperty("systemsManager", &systemsManager);
}

void Runtime::run()

{
    std::cout << "MAIN LOOP!!!" << std::endl;
    printDebugInfo();
    std::cout << "rendersystem size: "
              << systemsManager.renderSystem.iterContainer.size() << std::endl;
    std::cout << "behaviorsystem size: "
              << systemsManager.behaviorSystem.iterContainer.size()
              << std::endl;
    std::cout << "coordinatesystem size: "
              << systemsManager.coordinateSystem.iterContainer.size()
              << std::endl;

    // int runonce = false;

    auto lastTime = std::chrono::high_resolution_clock::now();
    int frameCount = 0;
    // runtime loop --------------------------------------
    while (running) {
        frameCount++;
        auto currentTime = std::chrono::high_resolution_clock::now();
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
        std::chrono::duration<float> elapsedTime = currentTime - lastTime;
        /*
                if (!runonce) {
                    std::cout << "ALL ENTITIES:" << std::endl;
                    for (auto& comp :
           systemsManager.coordinateSystem.iterContainer) { std::cout <<
           "CoordinateComponent: " << comp.entityId
                                  << " x: " << comp.x << " y: " << comp.y <<
           std::endl; std::cout << "RenderComponent: " << comp.entityId << " x:
           "
                                  << systemsManager.renderSystem
                                         .getComponent(comp.entityId)
                                         .rect.x
                                  << " y: "
                                  << systemsManager.renderSystem
                                         .getComponent(comp.entityId)
                                         .rect.y
                                  << std::endl;
                    }
                    runonce = true;
                }
        */
        if (elapsedTime.count() >= 1.0f) {
            std::cout << "FPS: " << frameCount << std::endl;
            lastTime = currentTime;
            frameCount = 0;
        }
    }
    //------------------------------------------------------

    // cleanup of SDL stuff before exiting
    renderManager.cleanup();

    return;
}

};  // namespace runtime