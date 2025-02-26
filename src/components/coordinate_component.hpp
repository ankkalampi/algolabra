#include "component.hpp"

#include <vector>
namespace components
{

struct CoordinateComponent : public Component<CoordinateComponent> {
    int x, y;

    CoordinateComponent(int x, int y);
};

}  // namespace components