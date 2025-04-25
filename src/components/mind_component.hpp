#pragma once

#include "behavior_system.hpp"
#include "components/behavior_component.hpp"
#include "components/component.hpp"
#include "coordinate_system.hpp"
#include "neural/neural_net.hpp"
#include "world.hpp"

namespace components
{

struct MindComponent : public Component<MindComponent> {
    systems::CoordinateSystem* coordinateSystem;
    CoordinateComponent* coordinateComponent;
    BehaviorComponent* behaviorComponent;
    systems::BehaviorSystem* behaviorSystem;
    world::World* world;
    std::vector<world::Cell*> sensedCells;

    neural::NeuralNet neuralNet;

    MindComponent(systems::CoordinateSystem* coordinateSystem, systems::BehaviorSystem* behaviorSystem,
                  world::World* world);

    static void process(MindComponent& mindComp);

};
}  // namespace components