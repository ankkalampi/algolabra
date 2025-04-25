#include "mind_component.hpp"

#include "behavior_system.hpp"
#include "cell.hpp"
#include "components/behavior_component.hpp"
#include "neural/neural_utils.hpp"
#include <iostream>
#include <ostream>

namespace components
{
MindComponent::MindComponent(systems::CoordinateSystem* coordinateSystem, systems::BehaviorSystem* behaviorsystem,  
                             world::World* world)
    : coordinateSystem(coordinateSystem), behaviorSystem(behaviorsystem), world(world)
{
    coordinateComponent = &coordinateSystem->getComponent(entityId);
    behaviorComponent = &behaviorsystem->getComponent(entityId);
}

void MindComponent::process(MindComponent& mindComp)
{
    // check if coordinatecomponent pointer points to correct component. update,
    // if necessary
    if (!(mindComp.entityId == mindComp.coordinateComponent->entityId)) {
        mindComp.coordinateComponent =
            &mindComp.coordinateSystem->getComponent(mindComp.entityId);
    }

    
    //std::cout << "checking behavior component pointer" << std::endl;
    // check if behaviorcomponent pointer points to correct component. update,
    // if necessary
    if (!(mindComp.entityId == mindComp.behaviorComponent->entityId)) {
        //std::cout << "pointer not correct, correcting" << std::endl;
        mindComp.behaviorComponent =
            &mindComp.behaviorSystem->getComponent(mindComp.entityId);
            //std::cout << "pointer corrected" << std::endl;
    }

    //std::cout << "behavior component pointer checked" << std::endl;

    

    // collect sense data
    // resolve sense data as input for neural network
    mindComp.sensedCells = neural::getSenseData(
        mindComp.coordinateComponent->cell, mindComp.world);
    /*
mindComp.neuralNet.input = neural::getInput(neural::getSenseData(
    mindComp.coordinateComponent->cell, mindComp.world));
*/
    // calculate output action using neural network

    //std::cout << "preparing to update behavior component!" << std::endl;
        int val = 0;

        //std::cout << "evaluating sense data" << std::endl;


    for(world::Cell* cell : mindComp.sensedCells){

        if (cell != nullptr){
            if (cell->tenant == world::Cell::Tenant::Plant){
                val += 3;
            }
            } else{
            std::cout << "cell was nullptr!" << std::endl;
        }
    
        
        

    }
    std::cout << "sense data evaluated, val: " << val << std::endl;

    if (val >= 3){
        mindComp.behaviorComponent->direction = Direction::South;
    } else  {
        std::cout << "val was less than 3" << std::endl;
        mindComp.behaviorComponent->direction = Direction::West;
    }
    //else if (30 <= val) mindComp.behaviorComponent->direction = Direction::North;
    //else if (40 <= val) mindComp.behaviorComponent->direction = Direction::West;
    //else if (50 <= val) mindComp.behaviorComponent->direction = Direction::East;

    //std::cout << "direction updated!" << std::endl;

    mindComp.behaviorComponent->action  = Action::Move;
    

    
}
}  // namespace components