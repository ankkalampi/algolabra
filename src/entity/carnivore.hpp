#pragma once

#include "entity.hpp"

namespace entity {
    struct Carnivore : public Entity<Carnivore>{
        Carnivore(int id, int x, int y) : Entity<Carnivore>(id, x, y) {}

    };
};