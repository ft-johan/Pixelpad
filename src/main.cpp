#include "display.h"
#include "buttons.h"
#include "ui.h"

void setup()
{
    initDisplay();

    initButtons();

    showHomeScreen("Coding","</>");
}

void loop()
{
    switch(getButtonEvent())
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