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
#include "../include/world.hpp"


#include <glm/glm.hpp>
#include <libnoise/noise.h>

#include "../include/runtime.hpp"






namespace entity{



    struct Animal{
        int id;
        int foodEaten;
        int satiation;
        int age;
        enum AnimalType {Herbivore, Carnivore} type;
    };


    struct Plant{
        int id;
        int age;
        enum PlantSize {
                        Small,
                        Medium,
                        Big,
                        Huge
                        } size;

        enum PlantSafety {
                            Safe,
                            SlightlyPoisonous,
                            GreatlyPoisonous,
                            Deadly
                            } safety;
    };
};







int main(){
    

    runtime::init();

    runtime::run();

    return 0;

}
