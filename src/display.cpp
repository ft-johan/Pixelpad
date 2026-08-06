
#include "display.h"

#include <Wire.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C display(
    U8G2_R0,
    U8X8_PIN_NONE
);

void initDisplay()
{
    Wire.begin(21,22);

    display.begin();

    display.setFont(u8g2_font_ncenB14_tr);
}
void drawCenteredText(int y, const char* text)
{
    int width = display.getStrWidth(text);
    int x = (128 - width) / 2;

    display.drawStr(x, y, text);
}
void showBootScreen()
{
    display.clearBuffer();

    drawCenteredText(35, "PixelPad");

    display.sendBuffer();
}
void showHomeScreen(const char* profile)
{
    display.clearBuffer();

    // Title
    display.setFont(u8g2_font_6x13_tf);
    drawCenteredText(10, "PixelPad");

    // Divider
    display.drawHLine(0, 15, 128);

    // Main Text
    display.setFont(u8g2_font_ncenB14_tr);
    drawCenteredText(38, profile);

    // Status
    display.setFont(u8g2_font_6x10_tf);
    drawCenteredText(60, "Ready");

    display.sendBuffer();
}
void showMacroFeedback(const char* action)
{
    display.clearBuffer();

    display.setFont(u8g2_font_ncenB14_tr);
    drawCenteredText(28, action);

    display.setFont(u8g2_font_6x10_tf);
    drawCenteredText(52, "Launching...");

    display.sendBuffer();
}