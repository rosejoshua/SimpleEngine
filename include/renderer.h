#pragma once

#include <SDL.h>

 class Renderer
 {
  private:
    SDL_Renderer *sdlRenderer;
  public:
    Renderer();
    ~Renderer();

    bool init(bool vSync, SDL_Window* sdlWindow);
    void clear();
    SDL_Renderer* getSdlRendererPtr();
 };
 
