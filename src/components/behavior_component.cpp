#include "behavior_component.hpp"

#include "globals.hpp"
#include "systems/coordinate_system.hpp"

namespace components
{
systems::CoordinateSystem* components::BehaviorComponent::coordinateSystem =
    nullptr;
BehaviorComponent::BehaviorComponent(Pattern pattern)
    : pattern(pattern), counter(0)
{
    // find the corresponding coordinate component
    coordinateComponent = &coordinateSystem->getComponent(entityId);

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
    std::cout << "MOVING! entity: " << entityId << std::endl;

    switch (direction) {
        // y increases down, and decreases up in SDL
        // x increases right, and decreases left in SDL
    case Center:
        break;
    case North:
        if (coordinateComponent->y > 0) {
            coordinateComponent->y--;
        }
        break;
    case South:
        if (coordinateComponent->y < SCREEN_HEIGHT / CELL_SIZE) {
            coordinateComponent->y++;
        }
        break;
    case East:
        if (coordinateComponent->x < SCREEN_WIDTH / CELL_SIZE) {
            coordinateComponent->x++;
        }
        break;
    case West:
        if (coordinateComponent->x > 0)
            coordinateComponent->x--;
        break;
    case NorthEast:
        if (coordinateComponent->x > SCREEN_WIDTH / CELL_SIZE &&
            coordinateComponent->y > 0) {
            coordinateComponent->x++;
            coordinateComponent->y--;
        }

        break;
    case NorthWest:
        if (coordinateComponent->x > 0 && coordinateComponent->y > 0) {
            coordinateComponent->x--;
            coordinateComponent->y--;
        }

        break;
    case SouthEast:
        if (coordinateComponent->x > SCREEN_WIDTH / CELL_SIZE &&
            coordinateComponent->y < SCREEN_HEIGHT / CELL_SIZE) {
            coordinateComponent->x++;
            coordinateComponent->y++;
        }
        break;
    case SouthWest:
        if (coordinateComponent->x > 0 &&
            coordinateComponent->y < SCREEN_HEIGHT / CELL_SIZE) {
            coordinateComponent->x--;
            coordinateComponent->y++;
        }

        break;
    }
}
};  // namespace components