#pragma once

#include "../components/coordinate_component.hpp"
#include "../runtime/debuggable.hpp"
#include "system.hpp"

namespace systems
{
struct CoordinateSystem : public System<components::CoordinateComponent>,
                          public debug::Debuggable {
    CoordinateSystem();
};
};  // namespace systems