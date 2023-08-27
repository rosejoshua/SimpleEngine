#include <event_handler.h>

void EventHandler::processEvents(bool *appIsRunning, PlayerControls *player1Controls)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_KEYDOWN)
    {
      player1Controls->setKbdState(event.key.keysym.scancode, true);
    }
    else if (event.type == SDL_KEYUP)
    {
      player1Controls->setKbdState(event.key.keysym.scancode, false);
    }
    else if (event.type == SDL_QUIT)
    {
      std::cout << "quit event" << std::endl;
      *appIsRunning = false;
    }
  }
}
  