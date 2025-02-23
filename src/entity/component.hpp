#pragma once
namespace entity
{

template <typename T>
struct Component {
    // id that binds this component to an entity
    int entityId;

    Component<T>(int id) : entityId(id) {}
};

// process a component, used by owner system. Has to be specialized for each
// component type in respective code files
template <typename T>
void processComponent(Component<T>& component)
{
}
};  // namespace entity