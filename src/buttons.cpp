#include <Arduino.h>

#include "buttons.h"

// -------------------------
// Pin Definitions
// -------------------------
const uint8_t BTN1_PIN = 4;

// -------------------------
// Debounce
// -------------------------
const unsigned long DEBOUNCE_DELAY = 25;

void initButtons()
{
    pinMode(BTN1_PIN, INPUT_PULLUP);
}

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

    // Stable long enough?
    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY)
    {
        if (reading != stableState)
        {
            stableState = reading;

            // Button Pressed
            if (stableState == LOW)
            {
                return BUTTON_1;
            }
        }
    }

    return BUTTON_NONE;
}