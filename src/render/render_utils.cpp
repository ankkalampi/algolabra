#include "render_utils.hpp"

#include "../components/render_component.hpp"
#include "../systems/render_system.hpp"
#include "SDL3/SDL.h"
#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "globals.hpp"

#include <cstdint>
#include <cstring>
#include <iostream>
#include <ostream>

namespace render
{

void tryTestTexture(SDL_Texture *texture)
{
    // open direct access to texture pixels
    uint32_t *pixels;  // this will become start point of pixels in memory
    int pitch;         // this will become line length
    if (SDL_LockTexture(texture, NULL, (void **)&pixels, &pitch) != 0) {
        printf("SDL_LockTexture failed: %s\n", SDL_GetError());
        return;
    } else {
        printf("Test Texture locked successfully! Pitch: %d\n", pitch);
    }

    // convert pitch to conform with 32-bit pixels
    int pitchPixels = pitch / sizeof(uint32_t);

    SDL_UnlockTexture(texture);
}

// creates one big texture from all rendercomponents
// dramatically reduces number of render calls per tick
void updateTextureBasedOnRenderComponents(systems::RenderSystem &renderSystem,
                                          SDL_Texture *texture)
{
    // open direct access to texture pixels
    uint32_t *pixels;  // this will become start point of pixels in memory
    int pitch = 0;     // this will become line length
    if (SDL_LockTexture(texture, NULL, (void **)&pixels, &pitch) != 0) {
        printf("SDL_LockTexture failed: %s\n", SDL_GetError());
        // return;
    }

    // convert pitch to conform with 32-bit pixels
    int pitchPixels = pitch / sizeof(uint32_t);

    // buffer for updated pixels
    std::vector<uint32_t> pixelBuffer(SCREEN_WIDTH * SCREEN_HEIGHT, 0);
    uint32_t colr;

// parallelized with openmp
#pragma omp parallel for
    for (auto &rendComp : renderSystem.iterContainer) {
        // std::cout << "rendcomp color: " << COLOR << std::endl;
        colr = rendComp.color;
        // update pixels
        for (int y = std::max(0, rendComp.y);
             y < std::min(float(SCREEN_HEIGHT),
                          rendComp.frect.y + rendComp.frect.h);
             ++y) {
            for (int x = std::max(0.0f, rendComp.frect.x);
                 x < std::min(float(SCREEN_WIDTH),
                              rendComp.frect.x + rendComp.frect.w);
                 ++x) {
                pixelBuffer[y * pitchPixels + x] = rendComp.color;
            }
        }
    }

    // copy buffer to texture data
    std::memcpy(
        pixels, pixelBuffer.data(), pixelBuffer.size() * sizeof(uint32_t));

    // release the texture so it can be drawn
    SDL_UnlockTexture(texture);
}
};  // namespace render