#include "behavior_component.hpp"

#include "systems/coordinate_system.hpp"

namespace components
{
BehaviorComponent::BehaviorComponent(
    int entityId, Pattern pattern, systems::CoordinateSystem* coordinateSystem)
    : Component(entityId), pattern(pattern), counter(0)
{
    // find the corresponding coordinate component
    coordinateComponent = static_cast<CoordinateComponent*>(
        &coordinateSystem->getComponent(entityId));

    // set limit based on move pattern
    switch (pattern) {
    case Circles:
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);

        movementPlant.push_back(South);
        movementPlant.push_back(South);
        movementPlant.push_back(South);
        movementPlant.push_back(South);
        movementPlant.push_back(South);
        movementPlant.push_back(South);
        movementPlant.push_back(South);

        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);

        movementPlant.push_back(North);
        movementPlant.push_back(North);
        movementPlant.push_back(North);
        movementPlant.push_back(North);
        movementPlant.push_back(North);
        movementPlant.push_back(North);
        movementPlant.push_back(North);
        break;
    case StraightAndBack:
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);
        movementPlant.push_back(West);

        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        movementPlant.push_back(East);
        break;
    case Stay:
        break;
    case Careful:
        movementPlant.push_back(East);

        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        movementPlant.push_back(Center);

        movementPlant.push_back(East);

        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        movementPlant.push_back(Center);

        movementPlant.push_back(East);

        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        movementPlant.push_back(Center);

        movementPlant.push_back(West);

        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        movementPlant.push_back(Center);
        break;
    }
}

void BehaviorComponent::process(BehaviorComponent& behavComp)
{
    behavComp.move(behavComp.movementPlant[behavComp.counter]);

    if (behavComp.counter < behavComp.movementPlant.size()) {
        behavComp.counter++;
    } else {
        behavComp.counter = 0;
    }
}

void BehaviorComponent::move(Direction direction)
{
    switch (direction) {
        // y increases down, and decreases up in SDL
        // x increases right, and decreases left in SDL
    case Center:
        break;
    case North:
        coordinateComponent->y--;
        break;
    case South:
        coordinateComponent->y++;
        break;
    case East:
        coordinateComponent->x++;
        break;
    case West:
        coordinateComponent->x--;
        break;
    case NorthEast:
        coordinateComponent->x++;
        coordinateComponent->y--;
        break;
    case NorthWest:
        coordinateComponent->x--;
        coordinateComponent->y--;
        break;
    case SouthEast:
        coordinateComponent->x++;
        coordinateComponent->y++;
        break;
    case SouthWest:
        coordinateComponent->x--;
        coordinateComponent->y++;
        break;
    }
}
};  // namespace components