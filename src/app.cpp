// Author: Joshua Rose
// Date Created: 9/11/22
//
// This is some starter code to get your project going. I found SDL setup on Mac to be needlessly frustrating so I hope this helps.
// If you enjoy it please consider subscribing to my YouTube channel: @jrose.me 
// 
// I coded this and got it working on  MacOS Monterey 12.4, using SDL 2.24.0 and compiled with Clang++

#include <iostream>
#include <SDL.h>
#include <window.h>
#include <renderer.h>

int main(int argc, char const *argv[])
{
    int numMillisToThrottle = 6;
    bool appIsRunning = true;
    Settings settings;
    Window window;
    window.init(&settings);
    Renderer renderer;
    renderer.init(settings.getVSync(), window.getSdlWindowPtr());

    // SDL_Renderer *renderer = nullptr;

    SDL_Rect sdlRect;
    sdlRect.w = settings.getResW()/30;
    sdlRect.h = settings.getResH()/10;
    sdlRect.x = settings.getResW()/2 - sdlRect.w/2;
    sdlRect.y = settings.getResH()/2 - sdlRect.h/2;
    int numPixelsToMovePerFrame = sdlRect.w/4;

    bool upArrowDown = false;
    bool leftArrowDown = false;
    bool downArrowDown = false;
    bool rightArrowDown = false;
    
    Uint64 lastDrawTime = SDL_GetTicks64();

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL video system is ready to go\n";
    }

    // Create an application window with the following settings:
    // window = SDL_CreateWindow(
    //     "An SDL2 window",        // window title
    //     SDL_WINDOWPOS_UNDEFINED, // initial x position
    //     SDL_WINDOWPOS_UNDEFINED, // initial y position
    //     resW,                     // width, in pixels
    //     resH,                     // height, in pixels
    //     SDL_WINDOW_SHOWN         // flags - see below
    // );

    // Check that the window was successfully created
    // if (window == NULL)
    // {
    //     // In the case that the window could not be made...
    //     printf("Could not create window: %s\n", SDL_GetError());
    //     return 1;
    // }

    
    // if (renderer == NULL)
    // {
    //     // In the case that the renderer could not be made...
    //     printf("Could not create renderer: %s\n", SDL_GetError());
    //     return 1;
    // }

    //main game/app loop
    while (appIsRunning)
    {
        //slowing things down a little, you can delete this if you like
        while (SDL_GetTicks64() - lastDrawTime < numMillisToThrottle){}

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Handle each specific event
            if (event.type == SDL_QUIT)
            {
                appIsRunning = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                {
                upArrowDown = true;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                {
                leftArrowDown = true;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                {
                downArrowDown = true;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                {
                rightArrowDown = true;
                }
            }
            else if (event.type == SDL_KEYUP)
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                {
                upArrowDown = false;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                {
                leftArrowDown = false;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                {
                downArrowDown = false;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                {
                rightArrowDown = false;
                }
            }
        }

        //move rectangle
        if (upArrowDown)
        {
            sdlRect.y -= numPixelsToMovePerFrame;
        }
        if (leftArrowDown)
        {
            sdlRect.x -= numPixelsToMovePerFrame;
        }
        if (downArrowDown)
        {
            sdlRect.y += numPixelsToMovePerFrame;
        }
        if (rightArrowDown)
        {
            sdlRect.x += numPixelsToMovePerFrame;
        }

        //bounds checking and correction
        if (sdlRect.x < 0)
        {
            sdlRect.x = 0;
        }
        else if (sdlRect.x + sdlRect.w - 1 >= settings.getResW())
        {
            sdlRect.x = settings.getResW() - sdlRect.w;
        }
        if (sdlRect.y < 0)
        {
            sdlRect.y = 0;
        }
        else if (sdlRect.y + sdlRect.h - 1 >= settings.getResH())
        {
            sdlRect.y = settings.getResH() - sdlRect.h;
        }

        renderer.clear();

        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        // SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer.getSdlRendererPtr(), 255, 105, 180, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer.getSdlRendererPtr(), &sdlRect);
        SDL_RenderPresent(renderer.getSdlRendererPtr());
        
        lastDrawTime = SDL_GetTicks64();
    }

    // SDL_DestroyWindow(window);
    //SDL_DestroyRenderer(renderer);
    std::cout << "exiting..." << std::endl;
    SDL_Quit();
    return 0;
}
