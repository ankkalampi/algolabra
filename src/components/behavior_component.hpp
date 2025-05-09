#pragma once

#include "components/component.hpp"
#include "systems/coordinate_system.hpp"

#include <ostream>
#include <vector>

namespace components
{

enum class Pattern { Circles, StraightAndBack, Stay, Careful };

enum class Direction {
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

enum class Action { Move, Eat, Reproduce };

struct BehaviorComponent : public Component<BehaviorComponent> {
    Pattern pattern;
    int counter;
    CoordinateComponent* coordinateComponent;
    std::vector<Direction> movementPlant;

    systems::CoordinateSystem* coordinateSystem;

    Direction direction;
    Action action;

    BehaviorComponent(Pattern pattern,
                      systems::CoordinateSystem* coordinatesystem);

    static void process(BehaviorComponent& behavComp);

    void move(Direction direction);

    void eat(Direction direction);

    void mate(Direction direction);
};
};  // namespace components