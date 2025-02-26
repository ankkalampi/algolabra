#pragma once

#include "../components/coordinate_component.hpp"
#include "system.hpp"

namespace systems
{
struct CoordinateSystem : public System<components::CoordinateComponent> {
    CoordinateSystem() {}
};
};  // namespace systems