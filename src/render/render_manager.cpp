#include "render_manager.hpp"

#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "render/render.hpp"
#include "render/render_utils.hpp"
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
                                    SDL_TEXTUREACCESS_TARGET,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT);
}

void RenderManager::update()
{
    // clear screen
    SDL_RenderClear(renderer);
    // create texture from all rendercomponents.
    // highly parallelized and optimized
    updateTextureBasedOnRenderComponents(*renderSystem, entityLayer);

    // render terrain
    SDL_RenderTexture(renderer, terrainLayer, NULL, NULL);

    // render entities
    SDL_RenderTexture(renderer, entityLayer, NULL, NULL);

    // draw
    SDL_RenderPresent(renderer);

    // set fps
    SDL_Delay(FPS_DELAY);
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
    std::cout << "WE ARE STARTING RENDERMANAGER INIT!!!" << std::endl;
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError()
                  << std::endl;
        return 1;
    }
    std::cout << "SDL INITIALIZED!!" << std::endl;

    // create SDL Window
    window = SDL_CreateWindow("neural animals",

                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_RESIZABLE);

    if (!window) {
        std::cerr << "SDL Renderer creation failed: " << SDL_GetError()
                  << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    std::cout << "WINDOW CREATED!!" << std::endl;
    std::cout << "Window pointer: " << window << std::endl;

    // create SDL renderer
    renderer = SDL_CreateRenderer(window, NULL);

    if (renderer == nullptr) {
        std::cerr << "Renderer creation failed: " << SDL_GetError()
                  << std::endl;
    } else {
        std::cout << "renderer doing just fine!" << std::endl;
    }

    if (renderer == nullptr) {
        std::cerr << "Renderer is invalid! SDL_Error: " << SDL_GetError()
                  << std::endl;
        SDL_Quit();
        return 1;
    }

    return 0;
}
};  // namespace render