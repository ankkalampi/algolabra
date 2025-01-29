#include "render.hpp"

namespace render{

    // FORWARD DECLARATIONS
    SDL_Texture* createTerrainTexture(   
                                                SDL_Renderer* renderer,
                                                const std::vector<world::Cell>& cells,
                                                int cellSize);

    /////////////////////////////////////////////////////


    
    // renders the whole scene. This is called every tick
    void draw(){

        // draw content
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // use terrin texture for rendering
        SDL_RenderCopy(renderer,terrainTexture, nullptr, nullptr);

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

        std::unordered_map<world::Terrain, SDL_Color> terrainColors = {
            {world::Terrain::Water, {0, 0, 255, 255}},       // Sininen
            {world::Terrain::Grass, {0, 255, 0, 255}},       // Vihreä
            {world::Terrain::Sand, {194, 178, 128, 255}},    // Hiekan väri
            {world::Terrain::Rock, {128, 128, 128, 255}} // Harmaa
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
};