#pragma once

#include <Arduino.h>

enum ButtonEvent
{
    BUTTON_NONE,

    BUTTON_1,
    BUTTON_2,
    BUTTON_3,
    BUTTON_4,
    BUTTON_5,
    BUTTON_6,
    BUTTON_7,
    BUTTON_8,
    BUTTON_9,

    BUTTON_FN
};

void initButtons();

ButtonEvent getButtonEvent();