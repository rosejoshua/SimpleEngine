// Author: Joshua Rose
// Date Created: 

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <window.h>
#include <renderer.h>
#include <event_handler.h>
#include <player_controls.h>
#include <collision_object_rectangle.h>

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
    PlayerControls player1Controls(1);

    std::string swordUrl = "../assets/sword.png";
    CollisionObjectRectangle swords(swordUrl, renderer.getSdlRendererPtr());

    SDL_Texture *texture = IMG_LoadTexture(renderer.getSdlRendererPtr(), "../assets/sword.png");
    // int w = 0;
    // int h = 0;
    // SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    
    // std::cout << "width: " << w << std::endl;
    // std::cout << "height: " << h << std::endl;

    SDL_Rect destRect;
    destRect.w = 62;
    destRect.h = 300;
    destRect.x = settings.getResW()/2 - destRect.w/2;
    destRect.y = settings.getResH()/2 - destRect.h/2;
    
    Uint64 lastDrawTime = SDL_GetTicks64();

    if (SDL_Init(SDL_INIT_VIDEO) < 0){ std::cout << "SDL could not be initialized: " << SDL_GetError(); }

    //main game/app loop
    while (appIsRunning)
    {
        //slowing things down a little, you can delete this if you like
        while (SDL_GetTicks64() - lastDrawTime < numMillisToThrottle){}
        eventHandler.processEvents(&appIsRunning, &player1Controls);

        renderer.clear();
        SDL_RenderCopy(renderer.getSdlRendererPtr(), texture, NULL, &destRect);
        SDL_RenderPresent(renderer.getSdlRendererPtr());
        lastDrawTime = SDL_GetTicks64();
    }
    //destroy stuff
    SDL_DestroyTexture(texture);

    std::cout << "exiting..." << std::endl;
    SDL_Quit();
    return 0;
}
