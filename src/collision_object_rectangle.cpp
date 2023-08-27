#include <collision_object_rectangle.h>

CollisionObjectRectangle::CollisionObjectRectangle(std::string pathToPng, SDL_Renderer *pSdlRenderer)
{
  texture = Texture(pathToPng, pSdlRenderer);
}

void CollisionObjectRectangle::spawn(int x, int y)
{
  instancePositions.push_back(std::make_pair(x, y));
}