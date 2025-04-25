#include "entity_creators.hpp"

#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "components/behavior_component.hpp"
#include "components/mind_component.hpp"
#include "components/render_component.hpp"
#include "systems_manager.hpp"

namespace entity
{
void createPlant(engine::SystemsManager& sysManager, world::Cell* cell)
{
    SDL_Rect rect = {0, 0, 2, 2};
    SDL_Color color = {255, 0, 0, 255};
    uint32_t id = sysManager.giveID();

    cell->tenant = world::Cell::Tenant::Plant;

    components::CoordinateComponent coordinateComponent =
        components::CoordinateComponent(cell);
    components::RenderComponent renderComponent =
        components::RenderComponent(rect, color);

    coordinateComponent.entityId = id;
    renderComponent.entityId = id;

    sysManager.coordinateSystem.add(coordinateComponent);
    sysManager.renderSystem.add(renderComponent);
}

void createHerbivore(engine::SystemsManager& sysManager, world::Cell* cell)
{
    SDL_Rect rect = {0, 0, 4, 4};
    SDL_Color color = {15, 24, 100, 255};
    uint32_t id = sysManager.giveID();

    cell->tenant = world::Cell::Tenant::Herbivore;

    components::CoordinateComponent coordinateComponent =
        components::CoordinateComponent(cell);
    components::RenderComponent renderComponent =
        components::RenderComponent(rect, color);

        coordinateComponent.entityId = id;
    renderComponent.entityId = id;
    sysManager.coordinateSystem.add(coordinateComponent);
    sysManager.renderSystem.add(renderComponent);

    

    components::BehaviorComponent behaviorComponent =
        components::BehaviorComponent(components::Pattern::Circles,
                                      &sysManager.coordinateSystem);

                                      behaviorComponent.entityId = id;
                                      sysManager.behaviorSystem.add(behaviorComponent);

    components::MindComponent mindComponent = components::MindComponent(
                                        &sysManager.coordinateSystem, &sysManager.behaviorSystem, &sysManager.world);

    
    
    mindComponent.entityId = id;

    
    
    sysManager.mindSystem.add(mindComponent);
}

}  // namespace entity