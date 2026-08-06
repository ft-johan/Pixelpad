#include "buttons.h"

const uint8_t BTN1_PIN = 4;

// Debounce time
const unsigned long DEBOUNCE_DELAY = 25;

ButtonEvent getButtonEvent()
{
    static bool previousReading = HIGH;
    static bool stableState = HIGH;
    static unsigned long lastDebounceTime = 0;

    bool reading = digitalRead(BTN1_PIN);

    // Button changed?
    if (reading != previousReading)
    {
        lastDebounceTime = millis();
    }

    previousReading = reading;

    // Has it stayed stable long enough?
    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY)
    {
        if (reading != stableState)
        {
            stableState = reading;

            if (stableState == LOW)
            {
                return BUTTON_1;
            }
        }
    }

    return BUTTON_NONE;
}

void initButtons()
{
    pinMode(BTN1_PIN, INPUT_PULLUP);
}