#pragma once

// treshold values for perlin terrain generation
#include <string>
inline const float GRASS_TRESHOLD = 0.25f;
inline const float WATER_TRESHOLD = 0.5f;
inline const float SAND_TRESHOLD = 0.65f;

// const variables for screen size and world grid dimensions based on cell size
inline const int SCREEN_WIDTH = 1800;
inline const int SCREEN_HEIGHT = 1200;
inline const int CELL_SIZE = 1;
inline const int CELLS_HORIZONTAL = SCREEN_WIDTH / CELL_SIZE;
inline const int CELLS_VERTICAL = SCREEN_HEIGHT / CELL_SIZE;

// used for file i/o etc
// this is from CMake,
// if there are editor errors, running cmake or brun.sh -b should fix the issue
inline const std::string PROJECT_ROOT = PROJECT_ROOT_DIR;

// const variables for perlin noise generation
inline const double PERLIN_FREQUENCY = 0.1;
inline const double PERLIN_PERSISTENCE = 0.9;
inline const double PERLIN_LACUNARITY = 9.0;
inline const double PERLIN_OCTAVE_COUNT = 1.0;
inline const float PERLIN_SCALE = 0.1f;

// const variables for rendering fps
inline const int FPS_DELAY = 16;

// const variables for entity spawning
inline const int SPAWN_MISS_LIMIT =
    100;  // how many times entity spawn can miss before giving up