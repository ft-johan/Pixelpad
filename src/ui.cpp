#include "ui.h"
#include "display.h"

void showHomeScreen(const char* title, const char* icon)
{
    clearDisplay();

    // Icon
    drawCenteredText(22, icon);

    // Profile Name
    drawCenteredText(50, title);

    updateDisplay();
}

void showFeedbackScreen(const char* title, const char* icon)
{
    clearDisplay();

    // Icon
    drawCenteredText(22, icon);

    // Macro Name
    drawCenteredText(50, title);

    updateDisplay();
}