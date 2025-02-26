#include "render_utils.hpp"

#include "../components/render_component.hpp"
#include "../systems/render_system.hpp"
#include "SDL3/SDL.h"
#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "globals.hpp"

#include <iostream>
#include <ostream>

namespace render
{

// creates one big texture from all rendercomponents
// dramatically reduces number of render calls per tick
void updateTextureBasedOnRenderComponents(systems::RenderSystem &renderSystem,
                                          SDL_Texture *texture)
{
    // open direct access to texture pixels
    uint32_t *pixels;  // this will become start point of pixels in memory
    int pitch;         // this will become line length
    SDL_LockTexture(texture, NULL, (void **)&pixels, &pitch);

    // convert pitch to conform with 32-bit pixels
    int pitchPixels = pitch / sizeof(uint32_t);

    // macros are evil, sure, but this loop really needs to be efficient,
    // and the other option would have been to expand these static cast
    // statements everywhere

#define X (static_cast<components::RenderComponent *>(&rendComp)->x)
#define Y (static_cast<components::RenderComponent *>(&rendComp)->y)
#define W (static_cast<components::RenderComponent *>(&rendComp)->w)
#define H (static_cast<components::RenderComponent *>(&rendComp)->h)
#define COLOR (static_cast<components::RenderComponent *>(&rendComp)->color)
// these are for enforcing texture boundaries
#define XSTART std::max(0, X)
#define YSTART std::max(0, Y)
#define XEND std::min(SCREEN_WIDTH, X + W)
#define YEND std::min(SCREEN_HEIGHT, Y + H)

// parallelized with openmp
#pragma omp for
    for (auto &rendComp : renderSystem.iterContainer) {
        // update pixels
        for (int y = YSTART; y < YEND; ++y) {
            for (int x = XSTART; x < XEND; ++x) {
                pixels[y * pitchPixels + x] = COLOR;
            }
        }
    }

    // let's get rid of these evil macros
#undef X
#undef Y
#undef W
#undef H
#undef COLOR
#undef XSTART
#undef YSTART
#undef XEND
#undef YEND

    // release the texture so it can be drawn
    SDL_UnlockTexture(texture);
}
};  // namespace render