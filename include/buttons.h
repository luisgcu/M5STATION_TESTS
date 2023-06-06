void btn_task(void *arg);
bool once2 = true;
#pragma once
#include <EasyButton.h>
// ButtonA
EasyButton buttonA(BTN_A_PIN);
// ButtonB
EasyButton buttonB(BTN_B_PIN);
// ButtonB
EasyButton buttonC(BTN_C_PIN);

// Callback function to be called when button1 is pressed
void onButtonAPressed()
{
    Serial2.println("ButtonA pressed");
}
void onButtonBPressed()
{
    Serial2.println("ButtonB pressed");
}
void onButtonCPressed()
{
    Serial2.println("ButtonC pressed");
}

void buttons_setup()
{

    // Initialize the buttons and Add the callback function to be called when the button2 is pressed.
    buttonA.begin();
    buttonB.begin();
    buttonC.begin();    
    buttonA.onPressed(onButtonAPressed);   
    buttonB.onPressed(onButtonBPressed);
    buttonC.onPressed(onButtonCPressed);
    // nothing here
    pinMode(BTN_A_PIN, INPUT_PULLUP);
    pinMode(BTN_B_PIN, INPUT_PULLUP);
    pinMode(BTN_C_PIN, INPUT_PULLUP);
    xTaskCreate(btn_task,   /* Task function. */
                "btn_task", /* String with name of task. */
                8096,       /* Stack size in bytes. */
                NULL,       /* Parameter passed as input of the task */
                1,          /* Priority of the task. */
                NULL);      /* Task handle. */
}

void btn_task(void *arg) // task runs on core 0
{
    while (1)
    {

        buttonA.read();
        buttonB.read();
        buttonC.read();
        vTaskDelay(200);
        if (once2 == true)
        {
            Serial2.print("btn_task running on core ");
            Serial2.println(xPortGetCoreID());
        }
        once2 = false;
    }
}
