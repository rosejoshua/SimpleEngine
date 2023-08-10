#include <controls_event_handler.h>

void ControlsEventHandler::processEvent(SDL_Event *event)
{
  std::cout << "contols event detected: " << (event->type == SDL_KEYDOWN ? "keydown" : "keyup") << std::endl;
}

  // if (event.type == SDL_KEYDOWN)
  // {
  //     if (event.key.keysym.scancode == SDL_SCANCODE_UP)
  //     {
  //     upArrowDown = true;
  //     }
  //     else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
  //     {
  //     leftArrowDown = true;
  //     }
  //     else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
  //     {
  //     downArrowDown = true;
  //     }
  //     else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
  //     {
  //     rightArrowDown = true;
  //     }
  // }
  // else if (event.type == SDL_KEYUP)
  // {
  //     if (event.key.keysym.scancode == SDL_SCANCODE_UP)
  //     {
  //     upArrowDown = false;
  //     }
  //     else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
  //     {
  //     leftArrowDown = false;
  //     }
  //     else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
  //     {
  //     downArrowDown = false;
  //     }
  //     else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
  //     {
  //     rightArrowDown = false;
  //     }
  // }