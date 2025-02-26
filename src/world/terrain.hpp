#pragma once

#include "noise/module/perlin.h"

#include <functional>     // std::hash
#include <unordered_map>  // std::unordered_map

namespace terrain
{

enum class Terrain { Grass = 1, Sand = 2, Water = 3, Rock = 4, NotSet = 5 };

// creates perlin generator to use with terrain generation
noise::module::Perlin generatePerlinGenerator(double freq,
                                              double pers,
                                              double lacun,
                                              double octave);

// determine terrain type baswd on treshold values in perlin terrain generation
Terrain determineTerrainType(float value);

};  // namespace terrain

// namespace std