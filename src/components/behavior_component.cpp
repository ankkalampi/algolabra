#include "behavior_component.hpp"

#include "cell.hpp"
#include "globals.hpp"
#include "systems/coordinate_system.hpp"

#include <iostream>

namespace components
{

BehaviorComponent::BehaviorComponent(
    Pattern pattern, systems::CoordinateSystem* coordinateSystem)
    : pattern(pattern), counter(0), coordinateSystem(coordinateSystem), action(Action::Eat), direction(Direction::East)
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
        std::cout << "INVALID PATTERN VALUE!!!" << std::endl;
        break;
    }
}

// resolves move function based on movement plan
// this will be replaced with neural net based movement
void BehaviorComponent::process(BehaviorComponent& behavComp)
{
    /*
    if (behavComp.counter < behavComp.movementPlant.size() - 1) {
        behavComp.counter++;
    } else {
        behavComp.counter = 0;
    }

    // check if coordinatecomponent pointer points to correct component. update,
    // if necessary
    if (!(behavComp.entityId == behavComp.coordinateComponent->entityId)) {
        behavComp.coordinateComponent =
            &behavComp.coordinateSystem->getComponent(behavComp.entityId);
    }

    behavComp.move(behavComp.movementPlant[behavComp.counter]);
    */
    //std::cout << "preparing to move!" << std::endl;
    if (behavComp.action == Action::Move) behavComp.move(behavComp.direction);
}

// updates corresponding coordinatecomponent based on direction given
void BehaviorComponent::move(Direction direction)
{
    // make current cell empty
    coordinateComponent->cell->tenant = world::Cell::Tenant::Empty;

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

        std::cout << std::endl
                  << "INVALID DIRECTION VALUE!!! VALUE: "
                  << static_cast<int>(direction) << std::endl;
        coordinateComponent->cell->tenant = world::Cell::Tenant::Herbivore;
        return;
    }

    // occupy updated cell
    coordinateComponent->cell->tenant = world::Cell::Tenant::Herbivore;
}


void eat(Direction direction){

}

void mate(Direction direction){


}
};  // namespace components