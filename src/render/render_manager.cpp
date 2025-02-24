#include "render_manager.hpp"

#include "SDL_render.h"
#include "SDL_video.h"
#include "render/render.hpp"
#include "render/render_utils.hpp"
#include "runtime/runtime.hpp"

namespace render
{
RenderManager::RenderManager(systems::RenderSystem& renderSystem,
                             runtime::Runtime& runtime)
    : renderSystem(renderSystem)
{
    init(renderer, window);
    terrainLayer =
        render::createTerrainTexture(renderer, runtime.world.cells, CELL_SIZE);
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
    updateTextureBasedOnRenderComponents(renderSystem, entityLayer);

    // render terrain
    SDL_RenderCopy(renderer, terrainLayer, NULL, NULL);

    // render entities
    SDL_RenderCopy(renderer, entityLayer, NULL, NULL);

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
};  // namespace render