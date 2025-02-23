#pragma once

#include "SDL_pixels.h"
#include "SDL_render.h"

#include <vector>
namespace render
{

struct RenderComponent {
    SDL_Rect rect;
};

SDL_Texture* createEntityTexture(
    SDL_Renderer* renderer,
    const std::vector<RenderComponent>& renderComponents)
{
}

}  // namespace render