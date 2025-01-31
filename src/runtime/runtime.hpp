#pragma once


#include "SDL_events.h"
#include "../world/world.hpp"


namespace runtime{

    inline bool running;
    inline SDL_Event event;

    // sets up the runtime system for simulation and rendering
    void init();

    // starts the runtime loop. Exits the program if window is closed
    void run();
    
};