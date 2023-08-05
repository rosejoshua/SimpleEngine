#pragma once

class Settings
{
  private:
    int resW;
    int resH;
    bool fullScreen;
    bool vSync;

  public:
    static const int defaultResW;
    static const int defaultResH;
    static const bool defaultFullScreen;
    static const bool defaultVSync;
    Settings();

    int getResW(){ return resW; }
    int getResH(){ return resH; }
    bool getFullScreen(){ return fullScreen; }
    bool getVSync(){ return vSync; }
};