#include "entity_system.hpp"

#include "systems/render_system.hpp"

namespace systems
{

EntitySystem::EntitySystem(CoordinateSystem* coordinateSystem,
                           RenderSystem* renderSystem,
                           BehaviorSystem* behaviorSystem)
    : coordinateSystem(coordinateSystem),
      renderSystem(renderSystem),
      behaviorSystem(behaviorSystem)
{
}

void EntitySystem::manifest(std::vector<std::any> components) {}
};  // namespace systems