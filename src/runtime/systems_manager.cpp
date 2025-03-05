#include "systems_manager.hpp"

#include "components/behavior_component.hpp"
#include "components/render_component.hpp"
#include "entity/entity_storage.hpp"
#include "systems/render_system.hpp"

#include <mutex>

namespace engine
{
SystemsManager::SystemsManager()
    : world(world::World(1, 1, 1, 1)),
      coordinateSystem(systems::CoordinateSystem()),
      renderSystem(systems::RenderSystem(&coordinateSystem)),
      behaviorSystem(systems::BehaviorSystem(&coordinateSystem)),
      entityStorage()

{
    addDebugName("SYSTEMS_MANAGER");
    addDebugProperty("coordinateSystem", &coordinateSystem);
    addDebugProperty("renderSystem", &renderSystem);
    addDebugProperty("behaviorSystem", &behaviorSystem);
    addDebugProperty("entityStorage", &entityStorage);
    addDebugProperty("componentStorage", &componentStorage);
    addDebugProperty("runningID", &runningID);
    addDebugProperty("mtx", &mtx);
}
uint32_t SystemsManager::giveID()
{
    std::lock_guard<std::mutex> lock(mtx);
    runningID++;
    return runningID;
}

void SystemsManager::manifest(std::vector<std::any>& components)
{
    uint32_t id = giveID();

    for (auto& component : components) {
        if (component.type() == typeid(components::RenderComponent)) {
            components::RenderComponent rendComp =
                std::any_cast<components::RenderComponent>(component);
            rendComp.entityId = id;
            renderSystem.add(rendComp);

        } else if (component.type() == typeid(components::BehaviorComponent)) {
            components::BehaviorComponent behavComp =
                std::any_cast<components::BehaviorComponent>(component);
            behavComp.entityId = id;
            behaviorSystem.add(behavComp);

        } else if (component.type() ==
                   typeid(components::CoordinateComponent)) {
            components::CoordinateComponent coordComp =
                std::any_cast<components::CoordinateComponent>(component);
            coordComp.entityId = id;
            coordinateSystem.add(coordComp);
        }
    }
}
}  // namespace engine