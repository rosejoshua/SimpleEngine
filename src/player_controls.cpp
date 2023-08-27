#include <player_controls.h>

PlayerControls::PlayerControls(int playerNumber)
{
  this->playerNumber = playerNumber;
  up = false;
  down = false;
  left = false;
  right = false;
  btn1 = false;
  btn2 = false;
  startBtn = false;

  kbdUp = SDL_SCANCODE_W;
  kbdDown = SDL_SCANCODE_S;
  kbdLeft = SDL_SCANCODE_A;
  kbdRight = SDL_SCANCODE_D;
  kbdBtn1 = SDL_SCANCODE_J;
  kbdBtn2 = SDL_SCANCODE_K;
  kbdStartBtn = SDL_SCANCODE_ESCAPE;

  mapKeyboardToBools();
}

void PlayerControls::mapKeyboardToBools()
{
  keyboardMap[kbdUp] = &up;
  keyboardMap[kbdDown] = &down;
  keyboardMap[kbdLeft] = &left;
  keyboardMap[kbdRight] = &right;
  keyboardMap[kbdBtn1] = &btn1;
  keyboardMap[kbdBtn2] = &btn2;
  keyboardMap[kbdStartBtn] = &startBtn;
}

void PlayerControls::reMapKeyboardToBools()
{
  keyboardMap.clear();
  mapKeyboardToBools();
}

void PlayerControls::setKbdState(SDL_Scancode scancode, bool pressed)
{
  if (keyboardMap.count(scancode) > 0)
  {
    *keyboardMap[scancode] = pressed;
    std::cout << "mapped key pressed or released: " << SDL_GetScancodeName(scancode) << std::endl;
  }
}

void PlayerControls::remapKbdUp(SDL_Scancode newScancode)
{
  kbdUp = newScancode;
  reMapKeyboardToBools();
}

void PlayerControls::remapKbdDown(SDL_Scancode newScancode)
{
  kbdDown = newScancode;
  reMapKeyboardToBools();
}

void PlayerControls::remapKbdLeft(SDL_Scancode newScancode)
{
  kbdLeft = newScancode;
  reMapKeyboardToBools();
}

void PlayerControls::remapKbdRight(SDL_Scancode newScancode)
{
  kbdRight = newScancode;
  reMapKeyboardToBools();
}

void PlayerControls::remapKbdBtn1(SDL_Scancode newScancode)
{
  kbdBtn1 = newScancode;
  reMapKeyboardToBools();
}

void PlayerControls::remapKbdBtn2(SDL_Scancode newScancode)
{
  kbdBtn2 = newScancode;
  reMapKeyboardToBools();
}

void PlayerControls::remapKbdStartBtn(SDL_Scancode newScancode)
{
  kbdStartBtn = newScancode;
  reMapKeyboardToBools();
}

void PlayerControls::printControlsState()
{
  std::cout << "up = " << up << std::endl;
  std::cout << "down = " << down << std::endl;
  std::cout << "left = " << left << std::endl;
  std::cout << "right = " << right << std::endl;
  std::cout << "btn1 = " << btn1 << std::endl;
  std::cout << "btn2 = " << btn2 << std::endl;
  std::cout << "start = " << startBtn << std::endl;
}