#pragma once

#include "SDL_render.h"
#include "systems/render_system.hpp"
namespace render
{

void updateTextureBasedOnRenderComponents(systems::RenderSystem& renderSystem,
                                          SDL_Texture* texture);
};