#include "behavior_system.hpp"

namespace systems
{
BehaviorSystem::BehaviorSystem(CoordinateSystem* coordinateSystem)
    : coordinateSystem(coordinateSystem)
{
    addDebugName("BEHAVIOR_SYSTEM");
    addDebugProperty("coordinateSystem", &coordinateSystem);
}
}  // namespace systems