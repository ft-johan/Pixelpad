#pragma once

#include <Arduino.h>
#include "buttons.h"

void uiInit();

void uiHandleButton(ButtonEvent event);

void uiUpdate();