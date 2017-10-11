#include <SDL.h>
#include <stdio.h>

#include <iostream>
#include <fstream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* workerSurface = NULL;

FILE* log;

void quit() {
    fclose(log);

    SDL_FreeSurface(workerSurface);
    workerSurface = NULL;

    SDL_FreeSurface(screenSurface);
    screenSurface = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

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
    return true;
}

bool loadMedia() {
    workerSurface = SDL_LoadBMP("res/img/worker.bmp");
    if (workerSurface == NULL) {
        printf("ERROR: Failed to load image %s! SDL_Error: %s\n", "worker.bmp", SDL_GetError());
        return false;
    }

    return true;
}

int main(int argc, char* args[]) {
    log = freopen ("log.log", "wb", stdout);

    if (!init()) {
        printf("ERROR: Failed to initialize!\n");
        return -10;
    }
    
    if (!loadMedia()) {
        printf("ERROR: Failed to load media!\n");
        return -20;
    }

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x23, 0x23, 0x23));
    SDL_BlitSurface(workerSurface, NULL, screenSurface, NULL);
    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);

    quit();
    return 0;
}
