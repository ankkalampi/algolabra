#pragma once

#include "entity.hpp"

namespace entity {
    struct Herbivore : public Entity<Herbivore>{
        Herbivore(int id, int x, int y) : Entity<Herbivore>(id, x, y) {}
    };
};