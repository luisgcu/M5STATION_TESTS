#include <Arduino.h>
#include <FastLED.h>
#include "m5station.h"
#include <M5GFX.h>
#include <M5Unified.h>
#include "display.h"
#include "buttons.h"
#include "pixelleds.h"
// put function declarations here:




void setup() {
  // put your setup code here, to run once:
  display_setup();
  pixel_setup();
  buttons_setup();
  
}

void loop() {
  // put your main code here, to run repeatedly:
}

