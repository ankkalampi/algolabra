#include "render_system.hpp"

#include "components/render_component.hpp"

namespace systems
{
RenderSystem::RenderSystem(CoordinateSystem* coordinateSystem)
    : coordinateSystem(coordinateSystem)
{
    // set coordinatesystem towork with render components as well
    components::RenderComponent::coordinateSystem = coordinateSystem;

    addDebugName("RENDER_SYSTEM");
    addDebugProperty("coordinateSystem", coordinateSystem);
}
}  // namespace systems