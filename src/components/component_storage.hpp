#pragma once

#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "components/behavior_component.hpp"
#include "systems/coordinate_system.hpp"

#include <tuple>
namespace components
{

struct ComponentStorage : public debug::Debuggable {
    ComponentStorage();
    // Component argument list simplifications

    // BEHAVIOR COMPONENTS
    std::tuple<Pattern> CIRCLES;

    std::tuple<Pattern> STRAIGHTANDBACK;
    std::tuple<Pattern> STAY;

    std::tuple<Pattern> CAREFUL;

    SDL_Color col;
    SDL_Rect rec;

    // RENDER COMPONENTS
    std::tuple<SDL_Rect, SDL_Color> REDBOX;

    std::tuple<SDL_Rect, SDL_Color> GREENBOX;

    std::tuple<SDL_Rect, SDL_Color> BLUEBOX;
};

};  // namespace components