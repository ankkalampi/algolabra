#include "coordinate_component.hpp"

#include "component.hpp"
namespace components
{
CoordinateComponent::CoordinateComponent(world::Cell* cell)
    : x(cell->x), y(cell->y), cell(cell)
{
}
};  // namespace components