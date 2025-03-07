#include "mind_system.hpp"

#include "coordinate_system.hpp"

namespace systems
{
MindSystem::MindSystem(CoordinateSystem* coordinateSystem)
    : coordinateSystem(coordinateSystem)
{
}
}  // namespace systems