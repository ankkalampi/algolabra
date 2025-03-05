#pragma once

#include "SDL3/SDL_render.h"
#include "systems/render_system.hpp"
namespace render
{
void tryTestTexture(SDL_Texture* texture);

void updateTextureBasedOnRenderComponents(systems::RenderSystem& renderSystem,
                                          SDL_Texture* texture);
};  // namespace render