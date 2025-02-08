#pragma once

#include "entity.hpp"

namespace entity{



    struct Animal : public Entity<Animal>{
        
        int foodEaten;
        int satiation;
        int age;
        enum AnimalType {Herbivore, Carnivore} type;
    };

};