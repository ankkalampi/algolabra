#pragma once

#include "../globals.hpp"
#include "../world/world.hpp"
#include "SDL3/SDL_render.h"

#include <SDL3/SDL.h>
#include <unordered_map>
#include <vector>

namespace render
{

inline bool renderedonce = false;

// inline SDL_Renderer* renderer;
// inline SDL_Window* window;
// inline SDL_Texture* terrainTexture;

// renders the whole scene. This is called every tick
// void draw();

// destroys everything related to SDL. This is used when exiting program
// void cleanup();

// this function inits the rendering context creating renderer and window, and
// connecting them
int init();

// sets up terrain and everything else for rendering
// void setupRenderingSystem(const world::World& world);

// this function is used for rendering the world terrain to a texture
void worldToTexture(SDL_Renderer* renderer,
                    const std::vector<world::Cell>& cells);

// generate texture for world terrain. Using texture for terrain speeds up
// rendering significantly
SDL_Texture* createTerrainTexture(SDL_Renderer* renderer,
                                  const std::vector<world::Cell>& cells,
                                  int cellSize);

// renders plants
// void renderPlants(const world::World& world);

// tests rect rendering
// void testRectRendering();
};  // namespace render
