#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <libnoise/module/perlin.h>
#include <vector>
#include <unordered_map>

#include <glm/glm.hpp>
#include <libnoise/noise.h>


// const variables for screen size and world grid dimensions based on cell size
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1200;
const int CELL_SIZE = 4;
const int CELLS_HORIZONTAL = SCREEN_WIDTH / CELL_SIZE;
const int CELLS_VERTICAL = SCREEN_HEIGHT / CELL_SIZE;

// const variables for perlin noise generation
const double PERLIN_FREQUENCY = 1.0;
const double PERLIN_PERSISTENCE = 0.5;
const double PERLIN_LACUNARITY = 2.0;
const double PERLIN_OCTAVE_COUNT = 6.0;
const float PERLIN_SCALE = 0.1f;

// treshold values for perlin terrain generation
const float GRASS_TRESHOLD = 0.3f;
const float WATER_TRESHOLD = 0.5f;
const float SAND_TRESHOLD = 0.7f;

namespace world{

    // forward declarations
    struct Animal;
    struct Plant;
    struct World;

    void generateTerrain(
                            World& world,
                            int amountWater,
                            int amountRock,
                            int amountSand,
                            int amountGrass);
    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants);
    ////////////////////////

    enum Terrain {
        Grass,
        Sand,
        Water,
        Rock,
        NotSet
    };

    struct Cell{
        Terrain terrain;
        enum Tenant {Empty, Herbivore, Predator} tenant;
        int tenantID;
        int x, y; 

        Cell(int x, int y) : x(x), y(y){
            this->tenantID = 0;
            this->tenant = Tenant::Empty;
        }
    };

    struct World{
        std::vector<Cell> cells;
        std::unordered_map<int, Animal*> animals;
        std::unordered_map<int, Plant*> plants;

        int plantSpawnRate;
        int plantSpawnDistance;
        int plantMaturityAge;

        int herbivoreMaturityAge;
        int herbivoreBirthSatiation;

        int carnivoreMaturityAge;
        int carnivoreBirthSatiation;


        World(
                
                int numberHerbivores,
                int numberCarnivores,
                int numberPlants,
                int amountGrass,
                int amountRock,
                int amountSand,
                int amountWater,
                int plantSpawnRate,
                int herbivoreMaturityAge,
                int herbivoreBirthSatiation,
                int carnivoreMaturityAge,
                int carnivoreBirthSatiation)
                :
                plantSpawnRate(plantSpawnRate),
                herbivoreMaturityAge(herbivoreMaturityAge),
                herbivoreBirthSatiation(herbivoreBirthSatiation),
                carnivoreMaturityAge(carnivoreMaturityAge),
                carnivoreBirthSatiation(carnivoreBirthSatiation){

            

            // generate terrain and starting populations
            generateTerrain(*this, amountWater, amountRock, amountSand, amountGrass);
            populateWorld(*this, numberHerbivores, numberCarnivores, numberPlants);



        }


    };

    // creates perlin generator to use with terrain generation
    noise::module::Perlin generatePerlinGnerator(double freq, double pers, double lacun, double octave){
        noise::module::Perlin perlin;

        perlin.SetFrequency(freq);
        perlin.SetPersistence(pers);
        perlin.SetLacunarity(lacun);
        perlin.SetOctaveCount(octave);

        return perlin;
    }

    // determine terrain type baswd on treshold values in perlin terrain generation
    Terrain determineTerrainType(float value){
        if (value < GRASS_TRESHOLD){
            return Terrain::Grass;
        } else if (value < WATER_TRESHOLD){
            return Terrain::Water;
        } else if (value < SAND_TRESHOLD){
            return Terrain::Sand;
        } else{
            return Terrain::Rock;
        }
    }



    // generate terrain for a new world using perlin noise generator
    void generateTerrain(
                            World& world,
                            int amountWater,
                            int amountRock,
                            int amountSand,
                            int amountGrass){

        // create perlin generator
        noise::module::Perlin perlin = generatePerlinGnerator(
                                                                PERLIN_FREQUENCY,
                                                                PERLIN_PERSISTENCE,
                                                                PERLIN_LACUNARITY,
                                                                PERLIN_OCTAVE_COUNT);



        // create Cells
        for(int y = 0; y < CELLS_HORIZONTAL; ++y){
            for(int x = 0; x < CELLS_VERTICAL; ++x){
                world.cells.emplace_back(x, y);

                // scale coordinates for perlin
                double nx = x * PERLIN_SCALE;
                double ny = y * PERLIN_SCALE;

                // get noise value between -1, 1
                float noiseValue = perlin.GetValue(nx, ny, 0.0);

                // transform value to be between 0,1
                noiseValue = (noiseValue + 1.0f) / 2.0f;

                // assign terrain to cell based on noise value
                world.cells[y * CELLS_HORIZONTAL + x].terrain = determineTerrainType(noiseValue);
                
            }
        }
        

    }

    void populateWorld(
                        World& world,
                        int numberHerbivores,
                        int numberCarnivores,
                        int numberPlants){

    }
    
};

namespace entity{

    

    struct Animal{
        int id;
        int foodEaten;
        int satiation;
        int age;
        enum AnimalType {Herbivore, Carnivore} type;
    };


    struct Plant{
        int id;
        int age;
        enum PlantSize {
                        Small,
                        Medium,
                        Big,
                        Huge
                        } size;

        enum PlantSafety {
                            Safe,
                            SlightlyPoisonous,
                            GreatlyPoisonous,
                            Deadly
                            } safety;
    };
};


void renderWorld(SDL_Renderer* renderer, const std::vector<world::Cell>& cells){

    std::unordered_map<world::Terrain, SDL_Color> terrainColors = {
        {world::Terrain::Water, {0, 0, 255, 255}},       // Sininen
        {world::Terrain::Grass, {0, 255, 0, 255}},       // Vihreä
        {world::Terrain::Sand, {194, 178, 128, 255}},    // Hiekan väri
        {world::Terrain::Rock, {128, 128, 128, 255}} // Harmaa
    };

    for (int y = 0; y < CELLS_HORIZONTAL; ++y ){
        for (int x = 0; x < CELLS_VERTICAL; ++x){
            const world::Cell& cell = cells[y * CELLS_HORIZONTAL + x];

            // set color of cell
            SDL_Color color = terrainColors[cell.terrain];
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

            // draw cell
            SDL_Rect rect = {x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}





int main(){
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // create SDL Window
    SDL_Window* window = SDL_CreateWindow(
                                            "neural animals",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            SCREEN_WIDTH, 
                                            SCREEN_HEIGHT, 
                                            SDL_WINDOW_SHOWN); 

    if (!window){
        std::cerr << "SDL Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // create SDL renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(
                                                window, 
                                                -1,
                                                SDL_RENDERER_ACCELERATED);

    if (!window){
        std::cerr << "SDL Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    } 

    // main loop

    bool running  = true;
    SDL_Event event;



    world::World world = world::World(1,1,1,1,1,1,1,1,1,1,1,1);


    

    while(running){

        // check events, quit if window closed
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                running = false;
            }
        }

        // draw content
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        renderWorld(renderer, world.cells);

        SDL_RenderPresent(renderer);

        // set fps
        SDL_Delay(16);
    }


    // cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}