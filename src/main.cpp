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

    uiInit();
}

void loop()
{
    ButtonEvent event = getButtonEvent();

    if (event != BUTTON_NONE)
    {
        uiHandleButton(event);
    }

    uiUpdate();
}