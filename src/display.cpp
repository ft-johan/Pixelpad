#include "display.h"

#include <Wire.h>
#include <U8g2lib.h>

// SH1106 128x64 OLED
U8G2_SH1106_128X64_NONAME_F_HW_I2C display(
    U8G2_R0,
    U8X8_PIN_NONE
);

void initDisplay()
{
    Wire.begin(21, 22);

    display.begin();

    display.clearBuffer();

    display.sendBuffer();
}

void clearDisplay()
{
    display.clearBuffer();
}

void updateDisplay()
{
    display.sendBuffer();
}

void drawCenteredText(int y, const char* text)
{
    display.setFont(u8g2_font_logisoso20_tf);

    int width = display.getStrWidth(text);

    int x = (128 - width) / 2;

    display.drawStr(x, y, text);
}
void drawSmallCenteredAt(int y, const char* text)
{
    display.setFont(u8g2_font_6x12_tf);

    int width = display.getStrWidth(text);
    int x = (128 - width) / 2;

    display.drawStr(x, y, text);
}

void drawProgressBar(int blocks)
{
    const int x = 14;
    const int y = 27;
    const int width = 100;
    const int height = 10;

    display.drawFrame(x, y, width, height);

    for (int i = 0; i < blocks; i++)
    {
        display.drawBox(
            x + 2 + (i * 9),
            y + 2,
            7,
            6
        );
    }
}