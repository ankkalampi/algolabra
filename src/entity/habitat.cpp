#include "habitat.hpp"

#include "components/component.hpp"
#include "components/entity_component.hpp"
#include "globals.hpp"
#include "systems/system_utils.hpp"
#include "world/cell.hpp"

#include <exception>
#include <random>

namespace entity
{

Habitat::Habitat() {}

Habitat::Habitat(std::vector<world::Cell*> habitatCells)
{
    // create these for picking random items in cells vector
    cells = habitatCells;
    std::random_device rd;
    gen = std::mt19937(rd());
    if (cells.size() == 0) {
        distrib = std::uniform_int_distribution<size_t>(0, 0);
    } else {
        distrib = std::uniform_int_distribution<size_t>(0, cells.size() - 1);
    }

    addDebugName("HABITAT");
    addDebugProperty("cells", &cells);
    addDebugProperty("gen", &gen);
    addDebugProperty("distrib", &distrib);

    printDebugInfo();
}

// creating a given number of entities to the world using coordinates found
// in free habitat cells, and path to entity file. This could fail if free
// cell is not found fast enough
void Habitat::spawnEntity(engine::SystemsManager& systemsManager,
                          const std::vector<std::any>& components,
                          int num)
{
    components::CoordinateComponent coordinateComponent =
        components::CoordinateComponent(0, 0);

    std::vector<std::any> entityPrototype = components;

    entityPrototype.emplace_back(coordinateComponent);

    world::Cell* targetCell = nullptr;

    for (int i = 0; i < num; ++i) {
        // try to find a free cell within habitat. give up if nopt found until
        // limit

        bool limitReached = true;
        for (int j = 0; j < SPAWN_MISS_LIMIT; ++j) {
            // get random index
            int randIndex = distrib(gen);

            // pick random cell from habitat cells
            targetCell = cells[distrib(gen)];

            // if free cell found, update coordinate component with the
            // coordiantes of that cell. transltion has to be made from cell
            // coordinates to pixel coordinates
            if (targetCell->tenant == world::Cell::Tenant::Empty) {
                coordinateComponent.x =
                    world::Cell::translateCoordinate(targetCell->x);
                coordinateComponent.y =
                    world::Cell::translateCoordinate(targetCell->y);

                // entity component is added to entitysystem where it's given
                // real unique id. must be static cast since all system add
                // functions take component<T>
                systemsManager.manifest(entityPrototype);

                // successful creation, exit this loop and continue creating
                // entities
                limitReached = false;
                break;
            }
        }

        if (limitReached) {
            // print to console how many entities failed to be created. This
            // could be later changed to print to some log file
            std::cout << "NO FREE SPACE FOUND FOR ENTITY! " << num - i
                      << " ENTITIES NOT CREATED" << std::endl;

            // return from function
            return;
        }
    }
}

}  // namespace entity