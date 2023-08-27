#pragma once

#include <iostream>
#include <SDL.h>
#include <player_controls.h>

class EventHandler
{
  private:
  public:
    void processEvents(bool *appIsRunning, PlayerControls *player1Controls);
};