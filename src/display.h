
// images resources
#pragma once
void dis_task(void *arg);
M5GFX display;
M5Canvas canvas(&display);
// extern const unsigned char img_startup[64800];
// extern const unsigned char img_startup[64200];
// extern const unsigned char img_background[64800];
// extern const unsigned char imgiot[97200];

void display_setup()
{
    // Display setup
    xTaskCreate(dis_task,   /* Task function. */
                "dis_task", /* String with name of task. */
                8096,       /* Stack size in bytes. */
                NULL,       /* Parameter passed as input of the task */
                1,          /* Priority of the task. */
                NULL);      /* Task handle. */

    // display.begin();
    // display.fillScreen(TFT_BLACK);
}

void dis_task(void *arg) // task runs on core 0
{
    delay(50);
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
        display.drawBitmap(0, 0, 240, 135, mbox2);
        delay(3000);
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

    while (1)
    {
     delay(2);   
    }
}