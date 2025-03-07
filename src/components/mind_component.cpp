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
    // std::cout << "PROCESSING MIND: " << mindComp.entityId << std::endl;
    mindComp.sensedCells = neural::getSenseData(
        mindComp.coordinateComponent->cell, mindComp.world);
}
}  // namespace components