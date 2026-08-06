#include "buttons.h"

const uint8_t BTN1_PIN = 4;

bool previousState = HIGH;

void initButtons()
{
    pinMode(BTN1_PIN, INPUT_PULLUP);
}

ButtonEvent getButtonEvent()
{
    bool currentState = digitalRead(BTN1_PIN);

    // Detect HIGH -> LOW transition
    if (previousState == HIGH && currentState == LOW)
    {
        previousState = currentState;
        return BUTTON_1;
    }

    previousState = currentState;

    return BUTTON_NONE;
}