#pragma once

#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "components/behavior_component.hpp"
#include "systems/coordinate_system.hpp"

#include <tuple>
namespace components
{

struct ComponentStorage {
    ComponentStorage() {}
    // Component argument list simplifications

    // BEHAVIOR COMPONENTS
    std::tuple<Pattern> CIRCLES = std::make_tuple(Pattern::Circles);

    std::tuple<Pattern> STRAIGHTANDBACK =
        std::make_tuple(Pattern::StraightAndBack);

    std::tuple<Pattern> STAY = std::make_tuple(Pattern::Stay);

    std::tuple<Pattern> CAREFUL = std::make_tuple(Pattern::Careful);

    SDL_Color col;
    SDL_Rect rec;

    // RENDER COMPONENTS
    std::tuple<SDL_Rect, SDL_Color> REDBOX =
        std::make_tuple(rec = {0, 0, 1, 1}, col = {255, 0, 0, 255});

    std::tuple<SDL_Rect, SDL_Color> GREENBOX =
        std::make_tuple(rec = {0, 0, 1, 1}, col = {0, 0, 255, 255});

    std::tuple<SDL_Rect, SDL_Color> BLUEBOX =
        std::make_tuple(rec = {0, 0, 1, 1}, col = {0, 255, 0, 255});
};

};  // namespace components