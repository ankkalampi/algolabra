

#include "runtime/runtime.hpp"

int main()
{
    runtime::Runtime engine = runtime::Runtime();

    engine.systemsManager.world.grassHabitat.spawnEntity(
        engine.systemsManager, 0, 100000);

    engine.systemsManager.world.landHabitat.spawnEntity(
        engine.systemsManager, 1, 10000);

    engine.run();

    return 0;
}
