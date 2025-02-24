#pragma once

#include "component.hpp"

namespace components
{
struct EntityComponent : public Component<EntityComponent> {
};
};  // namespace components