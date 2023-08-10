#pragma once

#include <SDL.h>
#include <settings.h>

 class Renderer
 {
  private:
    SDL_Renderer *sdlRenderer;
  public:
    Renderer();
    ~Renderer();

    bool init(Settings *settings, SDL_Window* sdlWindow);
    void clear();
    SDL_Renderer* getSdlRendererPtr();
 };
 
