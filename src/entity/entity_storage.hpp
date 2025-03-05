#pragma once

#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "components/behavior_component.hpp"
#include "components/component_storage.hpp"
#include "components/render_component.hpp"
#include "systems/coordinate_system.hpp"

#include <any>
#include <tuple>

struct SystemsManager;
namespace entity
{
enum EntityType {
    Plant,
    Herbivore1,
    Herbivore2,
    Herbivore3,
    Herbivore4,
    Carnivore1,
    Carnivore2,
    Carnivore3

};

struct EntityStorage : public debug::Debuggable {
    components::ComponentStorage componentStorage;

    EntityStorage();

    std::vector<std::any> generateEntity(EntityType type);
};
};  // namespace entity