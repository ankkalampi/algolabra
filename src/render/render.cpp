#include "render.hpp"
#include "SDL_rect.h"
#include "SDL_render.h"
#include <vector>

namespace render{

    
    // renders the whole scene. This is called every tick
    void draw(){

        // draw content
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // use terrin texture for rendering
        SDL_RenderCopy(renderer,terrainTexture, nullptr, nullptr);
       
        // render plants
        renderPlants(world::world);

        
        SDL_RenderPresent(renderer);

        // set fps
        SDL_Delay(FPS_DELAY);
    }

    // destroys everything related to SDL. This is used when exiting program
    void cleanup(){
        SDL_DestroyTexture(terrainTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // this function inits the rendering context creating renderer and window, and connecting them
    int init(){
        // init SDL 
        if (SDL_Init(SDL_INIT_VIDEO) < 0){
            std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
            return 1;
        }

        // create SDL Window
        window = SDL_CreateWindow(
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
        renderer = SDL_CreateRenderer(
                                                    window,
                                                    -1,
                                                    SDL_RENDERER_ACCELERATED);

        if (!window){
            std::cerr << "SDL Renderer creation failed: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }

        return 0;
    }

    // sets up terrain and everything else for rendering
    void setupRenderingSystem(const world::World& world){
        init();
        terrainTexture = createTerrainTexture(renderer, world.cells, CELL_SIZE);
    }


     

    // this function is used for rendering the world terrain to a texture
    void worldToTexture(
                                SDL_Renderer* renderer,
                                const std::vector<world::Cell>& cells){

        std::unordered_map<terrain::Terrain, SDL_Color> terrainColors = {
            {terrain::Terrain::Water, {0, 0, 255, 255}},       // Sininen
            {terrain::Terrain::Grass, {0, 255, 0, 255}},       // Vihreä
            {terrain::Terrain::Sand, {194, 178, 128, 255}},    // Hiekan väri
            {terrain::Terrain::Rock, {128, 128, 128, 255}} // Harmaa
        };

        for (int y = 0; y < CELLS_VERTICAL; ++y ){
            for (int x = 0; x < CELLS_HORIZONTAL; ++x){
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

    // generate texture for world terrain. Using texture for terrain speeds up rendering significantly
    SDL_Texture* createTerrainTexture(   
                                                SDL_Renderer* renderer,
                                                const std::vector<world::Cell>& cells,
                                                int cellSize){
        // create SDL_Texture for rendering
        SDL_Texture* terrainTexture = SDL_CreateTexture(
                                                            renderer,
                                                            SDL_PIXELFORMAT_ABGR8888,
                                                            SDL_TEXTUREACCESS_TARGET,
                                                            SCREEN_WIDTH,
                                                            SCREEN_HEIGHT);

        if (!terrainTexture){
            std::cerr << "texture creation failed: " << SDL_GetError() << std::endl;
            return nullptr;
        }

        // setting the texture as render target
        SDL_SetRenderTarget(renderer,terrainTexture);

        // render all cells of the world to the texture
        worldToTexture(renderer, cells);

        // return render target to default window
        SDL_SetRenderTarget(renderer, nullptr);

        return terrainTexture;


    }


    // renders plants
    void renderPlants(const world::World& world){
        int index;

        if (!renderedonce){
            std::vector<int> keys;

        std::cout << "SIZE OF WORLD.PLANTS: " << world.plants.size() << std::endl;
        

        for (auto it = world.plants.begin(); it != world.plants.end(); ++it) {
            std::cout << "SIZE OF WORLD.PLANTS: " << world.plants.size() << std::endl;
            std::cout << "ITERATING!!!!!!" << std::endl;
            std::cout <<  it->first << std::endl;
        
            keys.push_back(it->first);
        }
        for (int ind : keys){
            std::cout << ind << std::endl;
        }
            renderedonce = true;
        }

        
        
        

        
        for (const auto& entry : world.plants) {
            
            // find index of the correct cell using the key of plant map
            index = entry.first;
            

            //std::cout << "rendering plant at index " << index << std::endl;
            //std::cout << "world.cells[index].x: " << world.cells[index].x << std::endl;

            // form SDL_Rect based on coordinates of the cell
            SDL_Rect plantRect;
            plantRect.x = world.cells[index].x * CELL_SIZE;
            plantRect.y = world.cells[index].y * CELL_SIZE;
            plantRect.w = 20;
            plantRect.h = 20;

            //std::cout << "rendering plant at (" << plantRect.x << ", " << plantRect.y << ")" << std::endl;

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &plantRect);
        }
    }

    // tests rect rendering
    void testRectRendering(){
        SDL_Rect testRect;
        testRect.x = 100;
        testRect.y = 200;
        testRect.w = 30;
        testRect.h = 40;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &testRect);
    }
};