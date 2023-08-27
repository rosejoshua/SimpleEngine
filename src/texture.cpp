#include <texture.h>

Texture::Texture()
{
  pTexture = nullptr;
}

Texture::Texture(std::string pathToPng, SDL_Renderer *pSdlRenderer)
{
  pTexture = IMG_LoadTexture(pSdlRenderer, pathToPng.c_str());
}

Texture::~Texture()
{
  SDL_DestroyTexture(pTexture);
}