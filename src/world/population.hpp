#pragma once

#include <unordered_map>
#include <vector>










namespace population{

    // generics for population
    template <typename T>
    struct Population {
        // map for quick search
        std::unordered_map<int, T*> searchContainer;
        // vector for quick iteration
        std::vector<T> iterContainer;

        // this map is used for finding correct entity in itercontainer when removing
        std::unordered_map<int, int> idToIndexMap;

        

        // update population, this is run each tick
        void update(){
            
            // iterates all entities of population
            for (const T& entity : this->iterContainer){
                entity.update(&this);
            }
        }


        // add new entity to population 
        void add(const T& entity){
            // add id and reference of entity to search container
            this->searchContainer[entity.id] = entity;

            // add id and index to idtoindexmap for quick removal
            this->idToIndexMap[entity.id] = this->iterContainer.size();

            // add reference of entity to iteration container
            this->iterContainer.push_back(entity);

            
        }


        // remove entity from population
        void remove(const T& entity){
            int id = entity.id;
            // find index of entity in itercontainer using pointer arithmetics
            size_t index = &entity - &this->iterContainer[0];

            // remove entity reference from search container
            this->searchContainer.erase(entity.id);

            // check if entity is the last item  in itercontainer, if not, swap with
            // last item, update idtoindex map before removing last item in itercontainer
            if (index != this->iterContainer.size()-1){
                // change idtoindex map so that this entity and last entity are swapped
                // this entity id -> last index
                this->idToIndexMap[id] = this->iterContainer.size()-1;
                // last entity id -> this entity index
                this->idToIndexMap[this->iterContainer[this->iterContainer.size()-1].id] = index;
                
            }

            // remove last entity
            this->iterContainer.pop_back();



        }
    };

    

   
};