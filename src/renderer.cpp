#include <renderer.h>

Renderer::Renderer()
{
  pSdlRenderer = nullptr;
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(pSdlRenderer);
}

bool Renderer::init(Settings *settings, SDL_Window* sdlWindow)
{
  if (settings->getVSync())
  {
    pSdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  }
  else
  {
    pSdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED );
  }

  return !(pSdlRenderer == nullptr);
}

void Renderer::clear()
{
  SDL_SetRenderDrawColor(pSdlRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(pSdlRenderer);
}

SDL_Renderer* Renderer::getSdlRendererPtr(){ return pSdlRenderer; }