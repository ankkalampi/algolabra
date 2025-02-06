#pragma once


#include "SDL_events.h"
#include "../world/world.hpp"
#include <optional>


namespace runtime{

    extern bool running;
    extern SDL_Event event;
    extern std::optional<world::World> world;
    extern std::optional<world::WorldParameters> worldParameters;

    // sets up the runtime system for simulation and rendering
    void init();

    // starts the runtime loop. Exits the program if window is closed
    void run();
    
};