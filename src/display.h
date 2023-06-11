
// images resources
#pragma once

M5GFX display;
M5Canvas canvas(&display);
// extern const unsigned char img_startup[64800];
// extern const unsigned char img_startup[64200];
// extern const unsigned char img_background[64800];
// extern const unsigned char imgiot[97200];

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
    // display.drawBitmap(0, 0, 240, 135, img_startup);
    display.drawBitmap(0, 0, 240, 135, imgiot);
    delay(2000);
    display.fillScreen(TFT_BLACK);
    display.setCursor(6, 10);
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.printf("IP: 192.168.22.34");
    display.drawRect(1, 1, 236, 40, BLUE);

    display.setCursor(6, 55);
    display.setTextColor(WHITE);
    display.printf("SSID: HEXACAMFL");
    display.drawRect(1, 44, 236, 40, RED);

    display.setTextSize(2);
    display.setCursor(6, 100);
    display.setTextColor(WHITE);
    display.printf("TIME:12:34:23");
    display.drawRect(1, 90, 236, 40, CYAN);
}