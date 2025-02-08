#pragma once

namespace entity{

    template <typename Derived>
    struct Entity{
        // id of entity. important for locating specific entity
        int id;
        // cell coordinates of an entity
        int x, y;
    };
};