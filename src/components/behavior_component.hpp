#pragma once

#include "components/component.hpp"
#include "systems/coordinate_system.hpp"

#include <ostream>
#include <vector>

namespace components
{

enum Pattern { Circles, StraightAndBack, Stay, Careful };

enum Direction {
    North,
    South,
    East,
    West,
    NorthEast,
    NorthWest,
    SouthEast,
    SouthWest,
    Center
};

struct BehaviorComponent : public Component<BehaviorComponent> {
    Pattern pattern;
    int counter;
    CoordinateComponent* coordinateComponent;
    std::vector<Direction> movementPlant;

    static systems::CoordinateSystem* coordinateSystem;

    BehaviorComponent(Pattern pattern);

    static void process(BehaviorComponent& behavComp);

    void move(Direction direction);
};
};  // namespace components