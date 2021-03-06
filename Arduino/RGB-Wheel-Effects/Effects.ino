int Colors[21][3] = {
  {255, 0, 0}, {0, 255, 0},
  { 0, 0, 255}, {255, 255, 0},
  {255, 0, 255}, {0, 255, 255},
  {255, 255, 255},

  {127, 0, 0}, {0, 127, 0},
  { 0, 0, 127}, {127, 127, 0},
  {127, 0, 127}, {0, 127, 127},
  {127, 127, 127},

  {64, 0, 0}, {0, 64, 0},
  { 0, 0, 64}, {64, 64, 0},
  {64, 0, 64}, {0, 64, 64},
  {64, 64, 64}
};

void OneColor() {
  EveryLed(Colors[color]);

  strip.show();
  delay(defaultDelay);
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; ++j) {
    for (i = 0; i < strip.numPixels(); ++i)
      strip.setPixelColor(i, Wheel((i + j) & 255));
      
    strip.show();
    delay(wait);
  }
}

void rainbowPerPixel(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; ++j) {
    for (i = 0; i < strip.numPixels(); ++i)
      strip.setPixelColor(i, Wheel((int)((i * 3.5f + j)) & 255));
      
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {

  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);

  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }

  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);

}
