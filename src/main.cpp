
#include "entity/entity_storage.hpp"
#include "runtime/engine.hpp"
#include "runtime/runtime.hpp"

int main()
{
    // runtime::init();

    // runtime::run();

    runtime::Runtime engine = runtime::Runtime();

    debug::Debuggable test = debug::Debuggable();

    engine.world.grassHabitat.spawnEntity(
        engine.systemsManager,
        engine.systemsManager.entityStorage.generateEntity(
            entity::EntityType::Plant),
        5000);

    engine.run();

    return 0;
}
