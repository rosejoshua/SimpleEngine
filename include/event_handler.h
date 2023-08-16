#pragma once

#include <iostream>
#include <SDL.h>

class EventHandler
{
  private:
  public:
    void processEvents(bool *appIsRunning);
};