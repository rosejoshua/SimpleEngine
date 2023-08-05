#pragma once

#include <SDL.h>
#include <settings.h>
class Window
{
  private:
    SDL_Window *sdlWindow;
  public:
    Window();
    ~Window();
    Window(int resW, int resH);
    Window(bool vSync);
    Window(int resW, int resH, bool vSync);
    bool init(Settings *settings);
    SDL_Window* getSdlWindowPtr();
};