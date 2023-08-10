// Author: Joshua Rose
// Date Created: 9/11/22
//
// This is some starter code to get your project going. I found SDL setup on Mac to be needlessly frustrating so I hope this helps.
// If you enjoy it please consider subscribing to my YouTube channel: @jrose.me 
// 
// I coded this and got it working on  MacOS Monterey 12.4, using SDL 2.24.0 and compiled with Clang++

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <window.h>
#include <renderer.h>
#include <controls_event_handler.h>

int main(int argc, char const *argv[])
{
    int numMillisToThrottle = 2;
    bool appIsRunning = true;
    Settings settings;
    Window window;
    window.init(&settings);
    Renderer renderer;
    renderer.init(&settings, window.getSdlWindowPtr());
    ControlsEventHandler controlsEventHandler;

    SDL_Texture *texture = IMG_LoadTexture(renderer.getSdlRendererPtr(), "../assets/sword.png");

    SDL_Rect srcRect;
    SDL_Rect destRect;
    destRect.w = 62;
    destRect.h = 300;
    destRect.x = settings.getResW()/2 - destRect.w/2;
    destRect.y = settings.getResH()/2 - destRect.h/2;
    // sdlRect.w = settings.getResW()/30;
    // sdlRect.h = settings.getResH()/10;
    srcRect.w = 62;
    srcRect.h = 300;
    srcRect.x = 0;
    srcRect.y = 0;

    float angle = 30.0f; // set the angle.
    SDL_Point rotateAxis;
    rotateAxis.x = srcRect.w/2;
    rotateAxis.y = srcRect.h;

    int numPixelsToMovePerFrame = 1;

    bool upArrowDown = false;
    bool leftArrowDown = false;
    bool downArrowDown = false;
    bool rightArrowDown = false;
    
    Uint64 lastDrawTime = SDL_GetTicks64();

    if (SDL_Init(SDL_INIT_VIDEO) < 0){ std::cout << "SDL could not be initialized: " << SDL_GetError(); }

    //main game/app loop
    while (appIsRunning)
    {
        //slowing things down a little, you can delete this if you like
        while (SDL_GetTicks64() - lastDrawTime < numMillisToThrottle){}
        SDL_Event event;
        SDL_Event *p_event = &event;
        while (SDL_PollEvent(&event))
        {
            // Handle each specific event
            if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
            {
                controlsEventHandler.processEvent(p_event);
            }
            else if (event.type == SDL_QUIT)
            {
                appIsRunning = false;
            }
        }

        //move rectangle
        if (upArrowDown)
        {
            destRect.y -= numPixelsToMovePerFrame;
        }
        if (leftArrowDown)
        {
            destRect.x -= numPixelsToMovePerFrame;
        }
        if (downArrowDown)
        {
            destRect.y += numPixelsToMovePerFrame;
        }
        if (rightArrowDown)
        {
            destRect.x += numPixelsToMovePerFrame;
        }

        //bounds checking and correction
        if (destRect.x < 0)
        {
            destRect.x = 0;
        }
        else if (destRect.x + destRect.w - 1 >= settings.getResW())
        {
            destRect.x = settings.getResW() - destRect.w;
        }
        if (destRect.y < 0)
        {
            destRect.y = 0;
        }
        else if (destRect.y + destRect.h - 1 >= settings.getResH())
        {
            destRect.y = settings.getResH() - destRect.h;
        }

        angle += 2.0f;
        if (angle>360.0)
            angle = 0.0f;

        renderer.clear();
        SDL_RenderCopyEx(renderer.getSdlRendererPtr(), texture, NULL, &destRect, angle, &rotateAxis, SDL_FLIP_NONE);
        SDL_RenderPresent(renderer.getSdlRendererPtr());
        lastDrawTime = SDL_GetTicks64();
    }

    std::cout << "exiting..." << std::endl;
    SDL_Quit();
    return 0;
}
