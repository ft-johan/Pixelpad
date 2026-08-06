#include "display.h"
#include "buttons.h"
#include "ui.h"
#include "animations.h"

void setup()
{
    initDisplay();

    initButtons();

    startBootAnimation();
}

void loop()
{
    if (!bootAnimationFinished())
    {
        updateBootAnimation();
        return;
    }

    switch(getButtonEvent())
    {
        case BUTTON_1:

            showFeedbackScreen(
                "ChatGPT",
                "</>"
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