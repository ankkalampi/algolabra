#pragma once

#include "cell.hpp"

namespace neural
{
struct Sense {
    std::vector<world::Cell*> cells;
};
}  // namespace neural