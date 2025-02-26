#pragma once

#include "component.hpp"
#include "systems/coordinate_system.hpp"

#include <typeinfo>

namespace components
{
struct EntityComponent : public Component<EntityComponent> {
    components::CoordinateComponent* coordinateComponent;
    std::vector<std::type_info> systemTypes;
};
};  // namespace components