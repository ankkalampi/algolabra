#include "entity_creators.hpp"

#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "components/behavior_component.hpp"
#include "components/render_component.hpp"
#include "systems_manager.hpp"

namespace entity
{
void createPlant(engine::SystemsManager& sysManager, int x, int y)
{
    SDL_Rect rect = {0, 0, 2, 2};
    SDL_Color color = {255, 0, 0, 255};
    uint32_t id = sysManager.giveID();

    components::CoordinateComponent coordinateComponent =
        components::CoordinateComponent(x, y);
    components::RenderComponent renderComponent =
        components::RenderComponent(rect, color);

    coordinateComponent.entityId = id;
    renderComponent.entityId = id;

    sysManager.coordinateSystem.add(coordinateComponent);
    sysManager.renderSystem.add(renderComponent);
}

void createHerbivore(engine::SystemsManager& sysManager, int x, int y)
{
    SDL_Rect rect = {0, 0, 4, 4};
    SDL_Color color = {15, 24, 100, 255};
    uint32_t id = sysManager.giveID();

    components::CoordinateComponent coordinateComponent =
        components::CoordinateComponent(x, y);
    components::RenderComponent renderComponent =
        components::RenderComponent(rect, color);

    components::BehaviorComponent behaviorComponent =
        components::BehaviorComponent(components::Pattern::Circles,
                                      &sysManager.coordinateSystem);

    coordinateComponent.entityId = id;
    renderComponent.entityId = id;
    behaviorComponent.entityId = id;

    sysManager.coordinateSystem.add(coordinateComponent);
    sysManager.renderSystem.add(renderComponent);
    sysManager.behaviorSystem.add(behaviorComponent);
}

}  // namespace entity