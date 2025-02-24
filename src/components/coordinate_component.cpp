#include "coordinate_component.hpp"

#include "component.hpp"
namespace components
{
CoordinateComponent::CoordinateComponent(int entityId, int x, int y)
    : Component(entityId), x(x), y(y)
{
}
};  // namespace components