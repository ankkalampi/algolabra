
#include "entity/entity_storage.hpp"
#include "runtime/runtime.hpp"

int main()
{
    // runtime::init();

    // runtime::run();

    runtime::Runtime engine = runtime::Runtime();

    std::cout << "starting to spawn entities in main loop!" << std::endl;
    engine.world.grassHabitat.spawnEntity(
        engine.systemsManager,
        engine.systemsManager.entityStorage.generateEntity(
            entity::EntityType::Plant),
        5000);

    engine.run();

    return 0;
}
