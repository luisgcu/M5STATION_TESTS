#include "config/all.h"
#include "display.h"
#include "buttons.h"
#include "pixelleds.h"

// put function declarations here:
//CRGB NeoPixel[7];
void led_brithe();
void set_led_color(int color);
void displayshowbuttons();
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
displayshowbuttons();


}

void displayshowbuttons(){
canvas.fillSprite(BLACK);
}