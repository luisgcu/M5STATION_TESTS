
// images resources
#pragma once

M5GFX display;
M5Canvas canvas(&display);
extern const unsigned char img_startup[64800];
extern const unsigned char img_background[64800];

void display_setup()
{
    // Display setup
    display.begin();
    display.fillScreen(TFT_BLACK);

    if (display.width() < display.height())
    {
        display.setRotation(display.getRotation() ^ 0);
    }
    canvas.createSprite(240, 135);
    canvas.setTextSize((float)canvas.width() / 150); // Use small font size
    canvas.setTextSize(3);
    display.drawBitmap(0, 0, 240, 135, img_startup);
}