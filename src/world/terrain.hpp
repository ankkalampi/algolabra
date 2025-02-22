#pragma once



#include "noise/module/perlin.h"


namespace terrain {



    enum Terrain {
            Grass,
            Sand,
            Water,
            Rock,
            NotSet
        };


        // creates perlin generator to use with terrain generation
        noise::module::Perlin generatePerlinGenerator(double freq, double pers, double lacun, double octave);

        // determine terrain type baswd on treshold values in perlin terrain generation
        Terrain determineTerrainType(float value);

        


   

        

};