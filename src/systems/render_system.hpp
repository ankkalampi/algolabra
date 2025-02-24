#pragma once

#include "components/render_component.hpp"
#include "system.hpp"

namespace systems
{
struct RenderSystem : public System<components::RenderComponent> {
};
};  // namespace systems