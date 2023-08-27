#pragma once

#include <string>
#include <SDL_image.h>
#include <SDL.h>

class Texture
{
  private:
    SDL_Rect drawAndCollisionRect;
    SDL_Texture *pTexture;
  public:
    Texture();
    Texture(std::string pathToPng, SDL_Renderer *pSdlRenderer);
    ~Texture();
};