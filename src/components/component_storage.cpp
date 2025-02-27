#include "component_storage.hpp"

namespace components
{
ComponentStorage::ComponentStorage()
{
    CIRCLES = std::make_tuple(Pattern::Circles);

    STRAIGHTANDBACK = std::make_tuple(Pattern::StraightAndBack);

    STAY = std::make_tuple(Pattern::Stay);

    CAREFUL = std::make_tuple(Pattern::Careful);

    SDL_Color col;
    SDL_Rect rec;

    // RENDER COMPONENTS
    REDBOX = std::make_tuple(rec = {0, 0, 1, 1}, col = {255, 0, 0, 255});

    GREENBOX = std::make_tuple(rec = {0, 0, 1, 1}, col = {0, 0, 255, 255});

    BLUEBOX = std::make_tuple(rec = {0, 0, 1, 1}, col = {0, 255, 0, 255});

    addDebugName("COMPONENT_STORAGE");
    addDebugProperty("CIRCLES", &CIRCLES);
    addDebugProperty("STRAIGHTANDBACK", &STRAIGHTANDBACK);
    addDebugProperty("STAY", &STAY);
    addDebugProperty("CAREFUL", &CAREFUL);
    addDebugProperty("REDBOX", &REDBOX);
    addDebugProperty("GREENBOX", &GREENBOX);
    addDebugProperty("BLUEBOX", &BLUEBOX);

    printDebugInfo();
}
}  // namespace components