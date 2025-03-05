
#include "entity/entity_storage.hpp"
#include "runtime/runtime.hpp"

int main()
{
    runtime::Runtime engine = runtime::Runtime();

    engine.systemsManager.world.grassHabitat.spawnEntity(
        engine.systemsManager, 0, 1);

    engine.systemsManager.world.landHabitat.spawnEntity(
        engine.systemsManager, 1, 5);

    engine.run();

    return 0;
}
