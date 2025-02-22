#include "cell.hpp"

namespace world{
    Cell::Cell(int x, int y) : x(x), y(y){
        this->tenantID = 0;
        this->tenant = Tenant::Empty;
    }
}
