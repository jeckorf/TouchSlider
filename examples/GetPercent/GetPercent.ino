#include <TouchSlider.h>

TouchSlider slider;

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Wait for serial connection
  slider.begin();
  Serial.println("Touch slider test");
}

void loop() {
  int value = slider.getPercent();
  Serial.print("Value: ");
  Serial.println(value);
  delay(100);  // Wait a short time before checking again
}
