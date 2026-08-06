#include <Arduino.h>

#include "display.h"
#include "buttons.h"

void setup()
{
    initDisplay();

    initButtons();

    showBootScreen();

    delay(1500);

    showHomeScreen("Coding");
}

void loop()
{
    switch(getButtonEvent())
{
    case BUTTON_1:

        showMacroFeedback("ChatGPT");

        delay(500);

        showHomeScreen("Coding");

        break;

    default:
        break;
}
}