
CRGB NeoPixel[7];
void led_brithe();
void set_led_color(int color);

void pixel_setup(){   

	FastLED.addLeds<SK6812, NEO_PIXEL_PIN, GRB>(NeoPixel, NEO_PIXEL_NUM);

	for (size_t i = 0; i < 7; i++)
	{
		NeoPixel[i] = CRGB(255, 0, 0);
		FastLED.show();
		delay(100);
	}
	for (size_t i = 0; i < 7; i++)
	{
		NeoPixel[i] = CRGB(0, 255, 0);
		FastLED.show();
		delay(100);
	}
	for (size_t i = 0; i < 7; i++)
	{
		NeoPixel[i] = CRGB(0, 0, 255);
		FastLED.show();
		delay(100);
	}
	FastLED.setBrightness(60);
	set_led_color(0x0000ff);

}

void led_brithe()
{
	for (size_t i = 100; i > 0; i--)
	{
		FastLED.setBrightness(i);
		FastLED.show();
	}
	for (size_t i = 0; i < 100; i++)
	{
		FastLED.setBrightness(i);
		FastLED.show();
	}
}

void set_led_color(int color)
{
	for (size_t i = 0; i < 7; i++)
	{
		NeoPixel[i] = color;
	}
	FastLED.show();
}