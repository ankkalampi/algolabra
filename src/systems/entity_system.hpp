#pragma once

#include "../components/component.hpp"
#include "../components/entity_component.hpp"
#include "system.hpp"

namespace systems
{
struct EntitySystem : public System<EntitySystem> {
    void add(components::Component<components::EntityComponent>);
};
};  // namespace systems