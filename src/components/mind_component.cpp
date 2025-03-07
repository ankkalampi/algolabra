#include "mind_component.hpp"

#include "neural/neural_utils.hpp"

namespace components
{
MindComponent::MindComponent(systems::CoordinateSystem* coordinateSystem,
                             world::World* world)
    : coordinateSystem(coordinateSystem), world(world)
{
    coordinateComponent = &coordinateSystem->getComponent(entityId);
}

void MindComponent::process(MindComponent& mindComp)
{
    // check if coordinatecomponent pointer points to correct component. update,
    // if necessary
    if (!(mindComp.entityId == mindComp.coordinateComponent->entityId)) {
        mindComp.coordinateComponent =
            &mindComp.coordinateSystem->getComponent(mindComp.entityId);
    }

    // collect sense data
    // resolve sense data as input for neural network
    mindComp.sensedCells = neural::getSenseData(
        mindComp.coordinateComponent->cell, mindComp.world);
    /*
mindComp.neuralNet.input = neural::getInput(neural::getSenseData(
    mindComp.coordinateComponent->cell, mindComp.world));
*/
    // calculate output action using neural network
}
}  // namespace components