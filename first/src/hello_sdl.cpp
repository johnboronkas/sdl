#include <SDL.h>
#include <stdio.h>

#include <iostream>
#include <fstream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

FILE* log;

void quit() {
    fclose(log);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("ERROR: SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        quit();
        return false;
    }
    
    window = SDL_CreateWindow("SDL Tutorial"
                              ,SDL_WINDOWPOS_UNDEFINED
                              ,SDL_WINDOWPOS_UNDEFINED
                              ,SCREEN_WIDTH
                              ,SCREEN_HEIGHT
                              ,SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("ERROR: Window could not be created! SDL_Error: %s\n", SDL_GetError());
        quit();
        return false;
    }

    screenSurface = SDL_GetWindowSurface(window);
    printf("Test2");
    return true;
}

int main(int argc, char* args[]) {
    log = freopen ("log.log", "wb", stdout);
    init();

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);

    quit();
    return 0;
}
