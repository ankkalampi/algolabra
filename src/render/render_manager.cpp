#include "render_manager.hpp"

#include "SDL3/SDL_oldnames.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_video.h"
#include "render/render.hpp"
#include "render/render_utils.hpp"
#include "render_system.hpp"
#include "runtime/runtime.hpp"

namespace render
{
RenderManager::RenderManager(systems::RenderSystem& renderSystem,
                             world::World& world)
    : renderSystem(&renderSystem)
{
    init();

    terrainLayer =
        render::createTerrainTexture(renderer, world.cells, CELL_SIZE);
    entityLayer = SDL_CreateTexture(renderer,
                                    SDL_PIXELFORMAT_ABGR8888,
                                    SDL_TEXTUREACCESS_STREAMING,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT);

    testTexture = SDL_CreateTexture(renderer,
                                    SDL_PIXELFORMAT_ABGR8888,
                                    SDL_TEXTUREACCESS_STREAMING,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT);

    if (!entityLayer) {
        printf("SDL_CreateTexture failed: %s\n", SDL_GetError());
    }

    addDebugName("RENDER_MANAGER");
    addDebugProperty("terrainLayer", &terrainLayer);
    addDebugProperty("entityLayer", &entityLayer);
    addDebugProperty("renderSystem", &this->renderSystem);
    addDebugProperty("renderer", &renderer);
    addDebugProperty("window", &window);
}

void RenderManager::update()
{
    // clear screen
    SDL_RenderClear(renderer);
    // create texture from all rendercomponents.
    // highly parallelized and optimized
    // updateTextureBasedOnRenderComponents(*renderSystem, entityLayer);

    // tryTestTexture(testTexture);

    // render terrain
    SDL_RenderTexture(renderer, terrainLayer, NULL, NULL);

    // render entities
    // SDL_RenderTexture(renderer, entityLayer, NULL, NULL);
    drawRenderComponents(*renderSystem, renderer);

    // draw
    SDL_RenderPresent(renderer);

    // set fps
    // SDL_Delay(FPS_DELAY);
}

void RenderManager::cleanup()
{
    SDL_DestroyTexture(terrainLayer);
    SDL_DestroyTexture(entityLayer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int RenderManager::init()
{
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError()
                  << std::endl;
        return 1;
    }

    // create SDL Window
    window = SDL_CreateWindow("neural animals",

                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              0);

    if (!window) {
        std::cerr << "SDL Renderer creation failed: " << SDL_GetError()
                  << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // create SDL renderer
    renderer = SDL_CreateRenderer(window, NULL);

    if (renderer == nullptr) {
        std::cerr << "Renderer creation failed: " << SDL_GetError()
                  << std::endl;
    }

    if (renderer == nullptr) {
        std::cerr << "Renderer is invalid! SDL_Error: " << SDL_GetError()
                  << std::endl;
        SDL_Quit();
        return 1;
    }

    return 0;
}

SDL_FRect toFRect(SDL_Rect& rect)
{
    return SDL_FRect{static_cast<float>(rect.x),
                     static_cast<float>(rect.y),
                     static_cast<float>(rect.w),
                     static_cast<float>(rect.h)};
}

void renderRect(SDL_Renderer* renderer, SDL_FRect* rect, SDL_Color& color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, rect);
}

void RenderManager::drawRenderComponents(systems::RenderSystem& renderSystem,
                                         SDL_Renderer* renderer)
{
    uint32_t num = 0;
    //#pragma omp parallel for
    for (auto& rendComp : renderSystem.iterContainer) {
        renderRect(renderer, &rendComp.frect, rendComp.Scolor);
    }
}

};  // namespace render