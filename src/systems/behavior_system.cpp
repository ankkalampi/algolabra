#include "behavior_system.hpp"

namespace systems
{
BehaviorSystem::BehaviorSystem(CoordinateSystem* coordinateSystem)
    : coordinateSystem(coordinateSystem)
{
    // set coordinatesystem towork with render components as well
    components::BehaviorComponent::coordinateSystem = coordinateSystem;

    addDebugName("BEHAVIOR_SYSTEM");
    addDebugProperty("coordinateSystem", &coordinateSystem);
}
}  // namespace systems