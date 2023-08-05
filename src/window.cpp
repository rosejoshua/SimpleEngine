#include <window.h>
#include <settings.h>

Window::Window()
{
  this->sdlWindow = nullptr;
}
Window::~Window()
{
  SDL_DestroyWindow(sdlWindow);
}

bool Window::init(Settings *settings)
{
      // Create an application window with the following settings:
    sdlWindow = SDL_CreateWindow(
        "Khaos Engine",        // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        settings->getResW(),     // width, in pixels
        settings->getResH(),     // height, in pixels
        SDL_WINDOW_SHOWN         // flags - see below
    );

    return (sdlWindow != nullptr);
}

SDL_Window* Window::getSdlWindowPtr(){ return sdlWindow; }