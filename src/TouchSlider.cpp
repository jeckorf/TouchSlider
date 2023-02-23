#include "TouchSlider.h"

TouchSlider::TouchSlider(uint8_t address, int touchThreshold) {
  MPR121_ADDR = address;
  touch_threshold = touchThreshold;
}

void TouchSlider::begin() {
  Wire.begin();
  mpr121.begin(MPR121_ADDR);
  last_touched = 0;
}

int TouchSlider::getPercent() {
  uint16_t touched = mpr121.touched();
  if (touched != last_touched) {
    int current_touch = -1;
    for (int i = 0; i < 12; i++) {
      if (touched & (1 << i)) {
        current_touch = i;
        break;
      }
    }
    if (current_touch >= 0) {
      int current_percent = (current_touch * 100) / 12;
      if (current_percent != percent) {
        percent = current_percent;
      }
    }
    last_touched = touched;
  }
  return percent;
}
