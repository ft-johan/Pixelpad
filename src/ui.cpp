#include "ui.h"
#include "display.h"

void showHomeScreen(const char* title,
                    const char* icon)
{
    clearDisplay();

    drawIcon(14, 38, icon);

    drawTitle(44, 40, title);

    updateDisplay();
}

void showFeedbackScreen(const char* title,
                        const char* icon)
{
    clearDisplay();

    drawIcon(14, 38, icon);

    drawTitle(44, 40, title);

    updateDisplay();
}