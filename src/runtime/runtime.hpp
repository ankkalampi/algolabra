#pragma once


#include "SDL_events.h"
#include "../render/render.hpp"
#include "../globals.hpp"
#include "../world/world.hpp"


namespace runtime{

    inline bool running;
    inline SDL_Event event;

    // sets up the runtime system for simulation and rendering
    inline void init(){

        // setting up the simulation world
        world::setupWorld();

        // setting up rendering system
        render::setupRenderingSystem(world::world);

        running = true;
    }

    // starts the runtime loop. Exits the program if window is closed
    inline void run(){

        // runtime loop --------------------------------------
        while(running){

            // check events, quit if window closed
            while(SDL_PollEvent(&event)){
                if (event.type == SDL_QUIT){
                    running = false;
                }
            }

            // draw situation on this tick
            render::draw();

        }
        //------------------------------------------------------

        // cleanup of SDL stuff before exiting
        render::cleanup();


        return;
    }
};