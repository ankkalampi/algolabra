#pragma once

#include "../world/population.hpp"



namespace entity{
    
    template <typename T>
    struct Entity{
        // id of entity. important for locating specific entity
        int id;
        // cell coordinates of an entity
        int x, y;

        // CRTP style function override for update function
        void update(population::Population<T>& population){
            static_cast<T*>(this)->updateImpl(population);
        }
        
    };
};