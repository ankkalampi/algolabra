#pragma once

#include "SDL_pixels.h"
#include "SDL_render.h"
#include "component.hpp"
#include "systems/coordinate_system.hpp"

#include <vector>
namespace components
{

struct RenderComponent : public Component<RenderComponent> {
    int x, y, w, h;
    uint32_t color;  // converted from SDL_Color

    RenderComponent(int entityId, const SDL_Rect& rect, const SDL_Color& color);

    static void process(RenderComponent& rendComp,
                        systems::CoordinateSystem& coordinateSystem);
};

}  // namespace components