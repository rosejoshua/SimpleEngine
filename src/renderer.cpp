#include <renderer.h>

Renderer::Renderer()
{
  this->sdlRenderer = nullptr;
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(sdlRenderer);
}

bool Renderer::init(Settings *settings, SDL_Window* sdlWindow)
{
  if (settings->getVSync())
  {
    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  }
  else
  {
    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED );
  }

  return !(sdlRenderer == nullptr);
}

void Renderer::clear()
{
  SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(sdlRenderer);
}

SDL_Renderer* Renderer::getSdlRendererPtr(){ return sdlRenderer; }