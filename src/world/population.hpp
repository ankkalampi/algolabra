#pragma once

#include <unordered_map>
#include <vector>



// forward declaration
namespace entity{
    template <typename T> struct Entity;
}






namespace population{

    // generics for population
    template <typename T>
    struct Population {
        // vector for quick iteration
        std::vector<entity::Entity<T>> iterContainer;

        // this map is used for finding correct entity in itercontainer
        //  used whenever entity needs to be found
        std::unordered_map<int, std::size_t> idToIndexMap;


        // update population, this is run each tick
        void update(){
            
            // iterates all entities of population
            for (const entity::Entity<T>& entity : iterContainer){
                entity.update(&this);
            }
        }


        // add new entity to population 
        void add(entity::Entity<T>& entity){

            // add id and index to idtoindexmap for quick removal
            idToIndexMap[entity.id] = iterContainer.size();

            // add reference of entity to iteration container
            iterContainer.push_back(std::move(entity));

            
        }


        // remove entity from population
        void remove(int id){
            
            
            // find index of entity in itercontainer using idtoindexmap
            std::size_t index = idToIndexMap[id];


            // check if entity is the last item  in itercontainer, if not, swap with
            // last item, update idtoindex map before removing last item in itercontainer
            if (index != iterContainer.size()-1){
                // change idtoindex map so that this entity and last entity are swapped
                // this entity id -> last index
                idToIndexMap[id] = iterContainer.size()-1;
                // last entity id -> this entity index
                idToIndexMap[iterContainer[iterContainer.size()-1].id] = index;

                // swap last entity with entity to be removed
                std::swap(iterContainer[index], iterContainer[iterContainer.size() -1]);
                
            }
            // remove entity reference from idtoindexmap
            idToIndexMap.erase(id);

            // remove last entity
            iterContainer.pop_back();



        }
    };

    

   
};