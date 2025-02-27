#include "render.hpp"

#include "../runtime/runtime.hpp"
#include "../world/terrain.hpp"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"

#include <vector>

namespace render
{

SDL_FRect toFRect(const SDL_Rect& rect)
{
    return SDL_FRect{static_cast<float>(rect.x),
                     static_cast<float>(rect.y),
                     static_cast<float>(rect.w),
                     static_cast<float>(rect.h)};
}

// this function inits the rendering context creating renderer and window, and
// connecting them

// this function is used for rendering the world terrain to a texture
void worldToTexture(SDL_Renderer* renderer,
                    const std::vector<world::Cell>& cells)
{
    std::unordered_map<int, SDL_Color> terrainColors = {
        {1, {0, 0, 255, 255}},      // Sininen
        {2, {0, 255, 0, 255}},      // Vihreä
        {3, {194, 178, 128, 255}},  // Hiekan väri
        {4, {128, 128, 128, 255}}   // Harmaa
    };

    // TÄHÄN SYNTYY LOPUTON LUUPPI JOSTAIN SYYSTÄ
    for (int y = 0; y < CELLS_VERTICAL; ++y) {
        for (int x = 0; x < CELLS_HORIZONTAL; ++x) {
            const world::Cell& cell = cells[y * CELLS_HORIZONTAL + x];

            // set color of cell
            SDL_Color color = {0, 0, 0, 0};
            switch (cell.terrain) {
            case terrain::Terrain::Grass:
                color = terrainColors[2];
                break;
            case terrain::Terrain::Sand:
                color = terrainColors[3];
                break;
            case terrain::Terrain::Water:
                color = terrainColors[1];
                break;
            case terrain::Terrain::Rock:
                color = terrainColors[4];
                break;
            case terrain::Terrain::NotSet:
                break;
            }

            SDL_SetRenderDrawColor(
                renderer, color.r, color.g, color.b, color.a);

            // draw cell
            SDL_Rect rect = {
                x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            SDL_FRect fr = toFRect(rect);
            SDL_RenderFillRect(renderer, &fr);
        }
    }
}

// generate texture for world terrain. Using texture for terrain speeds up
// rendering significantly
SDL_Texture* createTerrainTexture(SDL_Renderer* renderer,
                                  const std::vector<world::Cell>& cells,
                                  int cellSize)
{
    // create SDL_Texture for rendering
    SDL_Texture* terrainTexture = SDL_CreateTexture(renderer,
                                                    SDL_PIXELFORMAT_ABGR8888,
                                                    SDL_TEXTUREACCESS_TARGET,
                                                    SCREEN_WIDTH,
                                                    SCREEN_HEIGHT);

    // setting the texture as render target
    SDL_SetRenderTarget(renderer, terrainTexture);

    // render all cells of the world to the texture
    worldToTexture(renderer, cells);

    // return render target to default window
    SDL_SetRenderTarget(renderer, nullptr);

    return terrainTexture;
}

};  // namespace render