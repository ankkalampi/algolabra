#pragma once
#include <fstream>
#include <iostream>
#include <tuple>
namespace components
{

template <typename T>
struct Component {
    // id that binds this component to an entity
    int entityId;

    Component() = default;

    // process a component, used by owner system. Has to be specialized for each
    // component type in respective code files
    static void processComponent(T& component) { T::process(component); }

    // generates component from argument list
    template <typename Tuple>
    static T generateComponent(const Tuple& tuple)
    {
        return std::apply([](auto&&... params) { return T(params...); }, tuple);
    }
};

};  // namespace components