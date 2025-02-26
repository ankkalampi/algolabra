#pragma once

#include "../systems/render_system.hpp"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "globals.hpp"
#include "render/render.hpp"

namespace render
{

// responsible for actual rendering tasks
struct RenderManager {
    SDL_Texture* terrainLayer;
    SDL_Texture* entityLayer;
    systems::RenderSystem* renderSystem;

    SDL_Renderer* renderer;
    SDL_Window* window;

    RenderManager(systems::RenderSystem& renderSystem, world::World& world);

    void update();

    int init();

    void cleanup();
};
};  // namespace render