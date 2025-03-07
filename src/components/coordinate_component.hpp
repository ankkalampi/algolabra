#include "cell.hpp"
#include "component.hpp"

#include <vector>
namespace components
{

struct CoordinateComponent : public Component<CoordinateComponent> {
    int x, y;
    world::Cell* cell;

    CoordinateComponent(world::Cell* cell);
};

}  // namespace components