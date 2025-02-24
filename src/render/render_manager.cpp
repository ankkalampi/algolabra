#include "render_manager.hpp"

#include "SDL_render.h"
#include "render/render_utils.hpp"

namespace render
{
RenderManager::RenderManager(systems::RenderSystem& renderSystem)
    : renderSystem(renderSystem)
{
    renderer = render::renderer;  // globaali muuttuja tullaan kapseloimaan
                                  // tähän luokkaan
    terrainLayer = render::createTerrainTexture(
        renderer, runtime::world->cells, CELL_SIZE);
    entityLayer = SDL_CreateTexture(renderer,
                                    SDL_PIXELFORMAT_ABGR8888,
                                    SDL_TEXTUREACCESS_TARGET,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT);
}

void RenderManager::Run()
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
}
};  // namespace render