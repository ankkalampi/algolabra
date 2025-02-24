#pragma once

#include "components/behavior_component.hpp"
#include "systems/system.hpp"

namespace systems
{
struct BehaviorSystem : public System<components::BehaviorComponent> {
};
};  // namespace systems