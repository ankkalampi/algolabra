#pragma once

#include "systems/system.hpp"

namespace systems
{
struct BehaviorSystem : public System<BehaviorSystem> {
};
};  // namespace systems