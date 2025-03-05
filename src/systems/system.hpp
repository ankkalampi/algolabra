#pragma once

#include "../components/component.hpp"

#include <unordered_map>
#include <vector>

namespace systems
{
template <typename T>
struct System {
    // vector for quick iteration
    std::vector<T> iterContainer;

    // this map is used for finding correct component in itercontainer
    //  used whenever component needs to be found
    std::unordered_map<int, std::size_t> idToIndexMap;

    // add new component to system
    void add(T &component)
    {
        // add id and index to idtoindexmap for quick removal
        idToIndexMap[component.entityId] = iterContainer.size();

        // add reference of component to iteration container
        iterContainer.push_back(std::move(component));
    }

    // remove component from system
    void remove(int id)
    {
        // find index of component in itercontainer using idtoindexmap
        std::size_t index = idToIndexMap[id];

        // check if component is the last item  in itercontainer, if not,
        // swap with last item, update idtoindexmap before removing
        // last item in itercontainer
        if (index != iterContainer.size() - 1) {
            // change idtoindex map so that this component and last
            // component are swapped this component id -> last index
            idToIndexMap[id] = iterContainer.size() - 1;
            // last component id -> this component index
            idToIndexMap[iterContainer[iterContainer.size() - 1].id] = index;

            // swap last component with component to be removed
            std::swap(iterContainer[index],
                      iterContainer[iterContainer.size() - 1]);
        }
        // remove component reference from idtoindexmap
        idToIndexMap.erase(id);

        // remove last component
        iterContainer.pop_back();
    }

    // returns reference to component based on entity id
    inline T &getComponent(int entityId)
    {
        return iterContainer[idToIndexMap[entityId]];
    }

    // update system, this is run each tick
    void updateComponents()
    {
        // iterates all entities of population
        for (T &component : iterContainer) {
            T::processComponent(component);
        }
    }
};
};  // namespace systems