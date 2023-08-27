#pragma once

#include <map>
#include <iostream>
#include <SDL.h>

class PlayerControls
{
  private:
    int playerNumber;
    std::map<SDL_Scancode, bool*> keyboardMap;

    //represent whether the mapped control/button is currently in a down or pressed state. 
    bool up;
    bool down;
    bool left;
    bool right;
    bool btn1;
    bool btn2;
    bool startBtn;

    //mapping for the keyboard control for the above button states
    SDL_Scancode kbdUp;
    SDL_Scancode kbdDown;
    SDL_Scancode kbdLeft;
    SDL_Scancode kbdRight;
    SDL_Scancode kbdBtn1;
    SDL_Scancode kbdBtn2;
    SDL_Scancode kbdStartBtn;

    //todo: mapping for gamepad

    void mapKeyboardToBools();
    void reMapKeyboardToBools();

  public:
    PlayerControls(int playerNumber);
    void setKbdState(SDL_Scancode scancode, bool pressed);
    void printControlsState();
    void remapKbdUp(SDL_Scancode newScancode);
    void remapKbdDown(SDL_Scancode newScancode);
    void remapKbdLeft(SDL_Scancode newScancode);
    void remapKbdRight(SDL_Scancode newScancode);
    void remapKbdBtn1(SDL_Scancode newScancode);
    void remapKbdBtn2(SDL_Scancode newScancode);
    void remapKbdStartBtn(SDL_Scancode newScancode);
};
