#pragma once

#include "components/mind_component.hpp"
#include "system.hpp"
namespace systems
{

struct CoordinateSystem;

struct MindSystem : public System<components::MindComponent> {
    CoordinateSystem* coordinateSystem;

    MindSystem(CoordinateSystem* coordinateSystem);
};
}  // namespace systems