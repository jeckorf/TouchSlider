#ifndef TouchSlider_h
#define TouchSlider_h

#include <Wire.h>
#include <Adafruit_MPR121.h>

class TouchSlider {
  public:
    TouchSlider(uint8_t address = 0x5A, int touchThreshold = 20);
    void begin();
    int getPercent();

  private:
    Adafruit_MPR121 mpr121;
    uint8_t MPR121_ADDR;
    int touch_threshold;
    int percent = 0;
    uint16_t last_touched;
};

#endif
