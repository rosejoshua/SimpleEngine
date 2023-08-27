#include <settings.h>
#include <iostream>
#include <fstream>
const int Settings::defaultResW = 1024;
const int Settings::defaultResH = 768;
const bool Settings::defaultFullScreen = false;
const bool Settings::defaultVSync = true;
Settings::Settings()
{
  try
  {
    std::ifstream cfgFile;
    cfgFile.open("settings.config");
    if (!cfgFile.is_open())
    {
      std::cout << "no settings.config found, loading default settings" << std::endl;
      this->resW = defaultResW;
      this->resH = defaultResH;
      this->fullScreen = defaultFullScreen;
      this->vSync = defaultVSync;
    }
    else
    {
      std::cout << "TODO: load saved settings" << std::endl;
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
}
