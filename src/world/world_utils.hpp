#pragma once



namespace world{

    struct World;

    // generate terrain for a new world using perlin noise generator
    void generateTerrain(
                        World& world,
                        int amountWater,
                        int amountRock,
                        int amountSand,
                        int amountGrass);
};

