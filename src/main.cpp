#include <Arduino.h>

#include "display.h"
#include "buttons.h"
#include "boot.h"
#include "ui.h"

void setup()
{
    initDisplay();
    initButtons();

    playBootSequence();

    showHomeScreen("Coding", "</>");
}

void loop()
{
    switch (getButtonEvent())
    {
        case BUTTON_1:

            showFeedbackScreen(
                "ChatGPT",
                "[]"
            );

            delay(500);

            showHomeScreen(
                "Coding",
                "</>"
            );

            break;

        default:
            break;
    }
}