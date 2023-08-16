// Author: Joshua Rose
// Date Created: 

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <window.h>
#include <renderer.h>
#include <event_handler.h>

int main(int argc, char const *argv[])
{
    int numMillisToThrottle = 4;
    bool appIsRunning = true;
    Settings settings;
    Window window;
    window.init(&settings);
    Renderer renderer;
    renderer.init(&settings, window.getSdlWindowPtr());
    EventHandler eventHandler;

    SDL_Texture *texture = IMG_LoadTexture(renderer.getSdlRendererPtr(), "../assets/sword.png");

    SDL_Rect srcRect;
    SDL_Rect destRect;
    destRect.w = 62;
    destRect.h = 300;
    destRect.x = settings.getResW()/2 - destRect.w/2;
    destRect.y = settings.getResH()/2 - destRect.h/2;

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
        eventHandler.processEvents(&appIsRunning);

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
