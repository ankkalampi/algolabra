#include "system_utils.hpp"

#include "globals.hpp"
#include "systems/entity_system.hpp"

#include <fstream>
#include <stdexcept>
#include <string>

namespace systems
{
// creates and returns entity based on entity file given. the created entity has
// the default id of 0. Proper id is created with mutex when entity is added to
// entity system. default coordinates 0,0 are also used, and they willl likewise
// be updated when entity is added to entity system

}  // namespace systems