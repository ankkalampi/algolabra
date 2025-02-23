#pragma once

#include <atomic>
#include <cstdint>

namespace population
{
template <typename T>
struct Population;
}

namespace entity
{

// every entity gets a unique id based on the current runningId
// this is atomic so that entity creation can be parallelized
static std::atomic<std::uint32_t> runningId(0);

template <typename T>
struct Entity {
    // id of entity. important for locating specific entity
    int id;
    // cell coordinates of an entity
    int x, y;

    Entity<T>() = default;

    // this constructor is for testing purposes
    Entity<T>(int id, int x, int y) : id(id), x(x), y(y) {}

    // actual real-world constructor
    Entity<T>(int x, int y) : x(x), y(y)
    {
        // atomic operation so that entity creation can be parallelized
        id = runningId.fetch_add(1, std::memory_order_relaxed);
    }

    // CRTP style function override for update function
    void updateEntity(population::Population<T> &population)
    {
        static_cast<T *>(this)->update(population);
    }
};
};  // namespace entity