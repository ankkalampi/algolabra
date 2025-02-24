#pragma once

#include "../runtime/runtime.hpp"
#include "../systems/render_system.hpp"
#include "SDL_render.h"
#include "globals.hpp"
#include "render/render.hpp"

namespace render
{
// responsible for actual rendering tasks
struct RenderManager {
    SDL_Renderer* renderer;
    SDL_Texture* terrainLayer;
    SDL_Texture* entityLayer;
    systems::RenderSystem& renderSystem;

    RenderManager(systems::RenderSystem& renderSystem);

    void Run();
};
};  // namespace render