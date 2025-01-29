#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "world/world.hpp"


#include <glm/glm.hpp>
#include <libnoise/noise.h>

#include "runtime/runtime.hpp"














int main(){
    

    runtime::init();

    runtime::run();

    return 0;

}
