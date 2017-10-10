#include <SDL.h>
#include <stdio.h>

#include <iostream>
#include <fstream>
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

FILE* log;

void quit(SDL_Window* window) {
    fclose(log);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* args[]) {
    log = freopen ("log.log", "wb", stdout);

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("ERROR: SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        quit(window);
        return -20;
    }
    
    window = SDL_CreateWindow("SDL Tutorial"
                              ,SDL_WINDOWPOS_UNDEFINED
                              ,SDL_WINDOWPOS_UNDEFINED
                              ,SCREEN_WIDTH
                              ,SCREEN_HEIGHT
                              ,SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("ERROR: Window could not be created! SDL_Error: %s\n", SDL_GetError());
        quit(window);
        return -30;
    }

    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);
    quit(window);
    return 0;
}
