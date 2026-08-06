#include "ui.h"
#include "display.h"

static unsigned long feedbackStartTime = 0;
static bool showingFeedback = false;

// -----------------------------
// Private Functions
// -----------------------------
static void drawHome()
{
    clearDisplay();

    drawCenteredText(22, "</>");
    drawCenteredText(50, "Coding");

    updateDisplay();
}

static void drawFeedback()
{
    clearDisplay();

    drawCenteredText(22, "[]");
    drawCenteredText(50, "ChatGPT");

    updateDisplay();
}

// -----------------------------
// Public Functions
// -----------------------------
void uiInit()
{
    drawHome();
}

void uiHandleButton(ButtonEvent event)
{
    switch (event)
    {
        case BUTTON_1:

            drawFeedback();

            showingFeedback = true;
            feedbackStartTime = millis();

            break;

        default:
            break;
    }
}

void uiUpdate()
{
    if (showingFeedback)
    {
        if (millis() - feedbackStartTime >= 500)
        {
            showingFeedback = false;

            drawHome();
        }
    }
}