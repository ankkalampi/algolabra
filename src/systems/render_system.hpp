#pragma once

#include "components/render_component.hpp"
#include "system.hpp"
#include "systems/coordinate_system.hpp"

namespace systems
{
struct RenderSystem : public System<components::RenderComponent> {
    CoordinateSystem* coordinateSystem;

    RenderSystem(CoordinateSystem* coordinateSystem)
        : coordinateSystem(coordinateSystem)
    {
    }
};
};  // namespace systems