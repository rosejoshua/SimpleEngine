#pragma once

#include <vector>
#include <texture.h>

class CollisionObjectRectangle
{
  private:
    Texture texture;
    std::vector<std::pair<int, int> > instancePositions;
  public:
    CollisionObjectRectangle(std::string pathToPng, SDL_Renderer *pSdlRenderer);
    void spawn(int x, int y);
};