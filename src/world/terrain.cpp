#include "terrain.hpp"
#include "../globals.hpp"


// creates perlin generator to use with terrain generation
    noise::module::Perlin generatePerlinGenerator(double freq, double pers, double lacun, double octave){
        noise::module::Perlin perlin;

        perlin.SetFrequency(freq);
        perlin.SetPersistence(pers);
        perlin.SetLacunarity(lacun);
        perlin.SetOctaveCount(octave);

        return perlin;
    }

    // determine terrain type baswd on treshold values in perlin terrain generation
    terrain::Terrain determineTerrainType(float value){
        if (value < GRASS_TRESHOLD){
            return terrain::Terrain::Water;
        } else if (value < WATER_TRESHOLD){
            return terrain::Terrain::Sand;
        } else if (value < SAND_TRESHOLD){
            return terrain::Terrain::Sand;
        } else{
            return terrain::Terrain::Grass;
        }
    }