#pragma once

#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "component.hpp"
#include "systems/coordinate_system.hpp"

#include <vector>
namespace components
{

struct RenderComponent : public Component<RenderComponent> {
    static systems::CoordinateSystem* coordinateSystem;
    int x, y, w, h;
    uint32_t color;  // converted from SDL_Color
    SDL_Rect rect;
    SDL_Color Scolor;

    SDL_FRect frect = {0.0f, 0.0f, 0.0f, 0.0f};

    RenderComponent(SDL_Rect& rect, SDL_Color& color);

    static void process(RenderComponent& rendComp);
};

}  // namespace components