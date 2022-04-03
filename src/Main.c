#include<stdio.h>
#include<SDL.h>
#define SCREEN_WIDTH 940    //window width
#define SCREEN_HEIGHT 680   //window height

struct ball{
    int x, y;   //position of the ball
    int w, h;   //width and height of the ball
}ball;

struct paddle{
    int x, y;   //position of the paddle
    int w, h;   //width and height of the paddle
}paddle_1, paddle_2;

int main(int argc, char *args[]){
    SDL_Window *window = NULL; //SDL_Window is a structure, declaring window pointer
    
    
    SDL_Surface *screenSurface = NULL; //SDL_Surface is a structure, declaring screenSurface pointer
    
    SDL_Init(SDL_INIT_VIDEO); //Initalization of SDL2

    //Creating a window with following settings   
    window = SDL_CreateWindow( 
        "Pong",                     //Window title
        SDL_WINDOWPOS_UNDEFINED,    //initial x position
        SDL_WINDOWPOS_UNDEFINED,    //initial y position
        SCREEN_WIDTH,               //width, in pixels
        SCREEN_HEIGHT,              //height, in pixels 
        0 
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
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
