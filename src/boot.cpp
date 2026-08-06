#include <Arduino.h>

#include "boot.h"
#include "display.h"

void playBootSequence()
{
    // -----------------------------
    // PixelPad Logo
    // -----------------------------
    clearDisplay();

    drawCenteredText(30, "PixelPad");
   drawSmallCenteredAt(46, "OS v0.1.0");

    updateDisplay();

    delay(800);

    // -----------------------------
    // Loading Screen
    // -----------------------------
    for (int i = 0; i <= 10; i++)
    {
        clearDisplay();



        drawProgressBar(i);

        updateDisplay();

        delay(120);
    }

    // -----------------------------
    // Ready
    // -----------------------------
    clearDisplay();



    updateDisplay();

    delay(500);

    clearDisplay();

    updateDisplay();

    delay(150);
}