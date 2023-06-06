#include <Arduino.h>
#include <FastLED.h>
#include "m5station.h"
#include <M5GFX.h>
#include <M5Unified.h>
#include "display.h"
#include "buttons.h"
#include "pixelleds.h"
#include <EasyButton.h>
#include "Ticker.h"
// put function declarations here:
bool once = true;
void setup()
{
  // put your setup code here, to run once:
  M5.begin();
  pinMode(PORT485_DE_RE, OUTPUT);
  digitalWrite(PORT485_DE_RE, HIGH); // DE&RE
  Serial2.begin(115200);
  Serial2.print("setup() running on core ");
  Serial2.println(xPortGetCoreID());
  display_setup();
  pixel_setup();
  buttons_setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (once == true)
  {
    Serial2.print("Loop() running on core ");
    Serial2.println(xPortGetCoreID());
    
  }
  once = false;
}
