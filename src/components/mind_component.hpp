#pragma once

#include "components/component.hpp"
#include "coordinate_system.hpp"
#include "neural/neural_net.hpp"
#include "world.hpp"

namespace components
{

struct MindComponent : public Component<MindComponent> {
    systems::CoordinateSystem* coordinateSystem;
    CoordinateComponent* coordinateComponent;
    world::World* world;
    std::vector<world::Cell*> sensedCells;

    neural::NeuralNet neuralNet;

    MindComponent(systems::CoordinateSystem* coordinateSystem,
                  world::World* world);

    static void process(MindComponent& mindComp);
};
}  // namespace components