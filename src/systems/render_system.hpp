#pragma once

#include "../runtime/debuggable.hpp"
#include "components/render_component.hpp"
#include "system.hpp"
#include "systems/coordinate_system.hpp"

namespace systems
{
struct RenderSystem : public System<components::RenderComponent>,
                      public debug::Debuggable {
    CoordinateSystem* coordinateSystem;

    RenderSystem(CoordinateSystem* coordinateSystem);
};
};  // namespace systems