
#include <unordered_map>
#include <vector>
#include "../entity/plant.hpp"
#include "../entity/animal.hpp"



namespace population{

    // generics for population
    template <typename T>
    struct Population {
        // map for quick search
        std::unordered_map<int, T&> searchContainer;
        // vector for quick iteration
        std::vector<T> iterContainer;

        // this map is used for finding correct entity in itercontainer when removing
        std::unordered_map<int, int> idToIndexMap;

        // update population, this is run each tick
        void update(){
            
            // iterates all entities of population
            for (const T& entity : this->iterContainer){
                entity.update();
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
            
        }
    };

   
};