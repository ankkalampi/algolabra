#include "SDL_events.h"
#include "../render/render.hpp"
#include "../globals.hpp"
#include "../world/world.hpp"
#include "runtime.hpp"


namespace runtime{

    std::optional<world::World> world;
    std::optional<world::WorldParameters> worldParameters;
    bool running;
    SDL_Event event;



    // sets up the runtime system for simulation and rendering
    void init(){

        worldParameters = world::WorldParameters(1,1,100000,1,1,1,1,1,1,1,1,1);

        // setting up the simulation world
        world::setupWorld(*world, *worldParameters);

        // setting up rendering system
        render::setupRenderingSystem(*world);

        running = true;
    }

    // starts the runtime loop. Exits the program if window is closed
    void run(){

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