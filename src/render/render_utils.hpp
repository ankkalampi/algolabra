#pragma once

#include "SDL_render.h"
#include "systems/render_system.hpp"
namespace render
{

int init(SDL_Renderer* renderer, SDL_Window* window);

void updateTextureBasedOnRenderComponents(systems::RenderSystem& renderSystem,
                                          SDL_Texture* texture);
};  // namespace render