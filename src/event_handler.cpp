#include <event_handler.h>

void EventHandler::processEvents(bool *appIsRunning)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
    {
      std::cout << "controls event" << std::endl;
    }
    else if (event.type == SDL_QUIT)
    {
      std::cout << "quit event" << std::endl;
      *appIsRunning = false;
    }
  }
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