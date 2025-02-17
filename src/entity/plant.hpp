#pragma once

#include "entity.hpp"

namespace entity{
    struct Plant : public Entity<Plant>{
      
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


        Plant(int id, int x, int y) : Entity<Plant>(id, x, y) {}
    };

    
};
    
