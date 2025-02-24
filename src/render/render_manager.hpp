#pragma once

#include "../systems/render_system.hpp"
#include "SDL_render.h"
#include "SDL_video.h"
#include "globals.hpp"
#include "render/render.hpp"

namespace runtime
{
struct Runtime;
}

namespace render
{
// responsible for actual rendering tasks
struct RenderManager {
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Texture* terrainLayer;
    SDL_Texture* entityLayer;
    systems::RenderSystem& renderSystem;

    RenderManager(systems::RenderSystem& renderSystem,
                  runtime::Runtime& runtime);

    void update();

    void cleanup();
};
};  // namespace render