#pragma once

#include "SDL_pixels.h"
#include "SDL_render.h"
#include "component.hpp"

#include <vector>
namespace components
{

struct RenderComponent : public Component<RenderComponent> {
    int x, y, w, h;
    uint32_t color;  // converted from SDL_Color
};

}  // namespace components