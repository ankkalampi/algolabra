#pragma once

#include "components/behavior_component.hpp"
#include "runtime/engine.hpp"
#include "systems/system.hpp"

namespace systems
{
struct BehaviorSystem : public System<components::BehaviorComponent>,
                        public debug::Debuggable {
    CoordinateSystem* coordinateSystem;

    BehaviorSystem(CoordinateSystem* coordinateSystem);
};
};  // namespace systems