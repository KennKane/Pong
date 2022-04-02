#include<stdio.h>
#include<SDL.h>
#define SCREEN_WIDTH 940
#define SCREEN_HEIGHT 680

int main(int argc, char *args[]){
    SDL_Window *window = NULL; //declaring pointer
    SDL_Surface *screenSurface = NULL; //declaring pointer
    
    SDL_Init(SDL_INIT_VIDEO); //Initalization of SDL2
    
    window = SDL_CreateWindow( 
        "Pong",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN 
    );
    //Checks if window was successfully created
    if(window == NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else{
        //Get window surface
        screenSurface = SDL_GetWindowSurface(window);

        //Fill the surface with desired color
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 32, 32, 32));
            
        //Update the surface
        SDL_UpdateWindowSurface(window);

        //Wait for 9 seconds
        SDL_Delay(9000);
    }
    
    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
