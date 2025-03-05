#include "behavior_component.hpp"

#include "globals.hpp"
#include "systems/coordinate_system.hpp"

#include <iostream>

namespace components
{

BehaviorComponent::BehaviorComponent(
    Pattern pattern, systems::CoordinateSystem* coordinateSystem)
    : pattern(pattern), counter(0), coordinateSystem(coordinateSystem)
{
    // find the corresponding coordinate component
    coordinateComponent = &coordinateSystem->getComponent(entityId);

    // set limit based on move pattern
    switch (pattern) {
    case Pattern::Circles:
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);

        movementPlant.push_back(Direction::South);
        movementPlant.push_back(Direction::South);
        movementPlant.push_back(Direction::South);
        movementPlant.push_back(Direction::South);
        movementPlant.push_back(Direction::South);
        movementPlant.push_back(Direction::South);
        movementPlant.push_back(Direction::South);

        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);

        movementPlant.push_back(Direction::North);
        movementPlant.push_back(Direction::North);
        movementPlant.push_back(Direction::North);
        movementPlant.push_back(Direction::North);
        movementPlant.push_back(Direction::North);
        movementPlant.push_back(Direction::North);
        movementPlant.push_back(Direction::North);
        break;
    case Pattern::StraightAndBack:
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);
        movementPlant.push_back(Direction::West);

        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        movementPlant.push_back(Direction::East);
        break;
    case Pattern::Stay:
        break;
    case Pattern::Careful:
        movementPlant.push_back(Direction::East);

        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);

        movementPlant.push_back(Direction::East);

        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);

        movementPlant.push_back(Direction::East);

        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);

        movementPlant.push_back(Direction::West);

        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        movementPlant.push_back(Direction::Center);
        break;

    default:
        // std::cout << "INVALID PATTERN VALUE!!!" << std::endl;
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
    std::cout << "CHECKING!!! BEHAVIORCOMP ID: " << entityId
              << " COORDINATECOMP ID: " << coordinateComponent->entityId
              << std::endl;
    std::cout << "MOVING! entity: " << entityId
              << " direction: " << static_cast<int>(direction)
              << " old coordinates:  x: " << coordinateComponent->x
              << " y: " << coordinateComponent->y;

    switch (direction) {
        // y increases down, and decreases up in SDL
        // x increases right, and decreases left in SDL
    case Direction::Center:
        break;
    case Direction::North:
        if (coordinateComponent->y > 0) {
            coordinateComponent->y--;
        }
        break;
    case Direction::South:
        if (coordinateComponent->y < SCREEN_HEIGHT / CELL_SIZE) {
            coordinateComponent->y++;
        }
        break;
    case Direction::East:
        if (coordinateComponent->x < SCREEN_WIDTH / CELL_SIZE) {
            coordinateComponent->x++;
        }
        break;
    case Direction::West:
        if (coordinateComponent->x > 0)
            coordinateComponent->x--;
        break;
    case Direction::NorthEast:
        if (coordinateComponent->x > SCREEN_WIDTH / CELL_SIZE &&
            coordinateComponent->y > 0) {
            coordinateComponent->x++;
            coordinateComponent->y--;
        }

        break;
    case Direction::NorthWest:
        if (coordinateComponent->x > 0 && coordinateComponent->y > 0) {
            coordinateComponent->x--;
            coordinateComponent->y--;
        }

        break;
    case Direction::SouthEast:
        if (coordinateComponent->x > SCREEN_WIDTH / CELL_SIZE &&
            coordinateComponent->y < SCREEN_HEIGHT / CELL_SIZE) {
            coordinateComponent->x++;
            coordinateComponent->y++;
        }
        break;
    case Direction::SouthWest:
        if (coordinateComponent->x > 0 &&
            coordinateComponent->y < SCREEN_HEIGHT / CELL_SIZE) {
            coordinateComponent->x--;
            coordinateComponent->y++;
        }

        break;
    default:

        // std::cout << std::endl << "INVALID DIRECTION VALUE!!!" << std::endl;

        return;
    }

    std::cout << " new: x: " << coordinateComponent->x
              << " y: " << coordinateComponent->y << std::endl;
}
};  // namespace components