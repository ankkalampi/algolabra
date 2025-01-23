#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <vector>
#include <unordered_map>

// const variables for screen size and world grid dimensions based on cell size
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
const int CELL_SIZE = 4;
const int CELLS_HORIZONTAL = SCREEN_WIDTH / CELL_SIZE;
const int CELLS_VERTICAL = SCREEN_HEIGHT / CELL_SIZE;

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

            // create Cells
            for(int i = 0; i < CELLS_HORIZONTAL; i++){
                for(int j = 0; j < CELLS_VERTICAL; j++){
                    this->cells.emplace_back(i, j);
                }
            }

            // generate terrain and starting populations
            generateTerrain(*this, amountWater, amountRock, amountSand, amountGrass);
            populateWorld(*this, numberHerbivores, numberCarnivores, numberPlants);



        }


    };



    void generateTerrain(
                            World& world,
                            int amountWater,
                            int amountRock,
                            int amountSand,
                            int amountGrass){

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

        // set fps
        SDL_Delay(16);
    }


    // cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}