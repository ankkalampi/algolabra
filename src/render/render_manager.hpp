#pragma once

#include "../systems/render_system.hpp"
#include "../world/world.hpp"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "globals.hpp"
#include "render/render.hpp"

namespace render
{

// responsible for actual rendering tasks
struct RenderManager : public debug::Debuggable {
    SDL_Texture* terrainLayer;
    SDL_Texture* entityLayer;

    SDL_Texture* testTexture;
    systems::RenderSystem* renderSystem;

    SDL_Renderer* renderer;
    SDL_Window* window;

    RenderManager(systems::RenderSystem& renderSystem, world::World& world);

    void update();

    int init();

    void cleanup();

    void drawRenderComponents(systems::RenderSystem& renderSystem,
                              SDL_Renderer* renderer);
};

SDL_FRect toFRect(SDL_Rect& rect);

void renderRect(SDL_Renderer* renderer, SDL_FRect* rect, SDL_Color& color);

};  // namespace render