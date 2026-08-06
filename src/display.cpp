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
}

void clearDisplay()
{
    display.clearBuffer();
}

void updateDisplay()
{
    display.sendBuffer();
}

void drawIcon(int x,
              int y,
              const char* icon)
{
    display.setFont(u8g2_font_8x13_tf);

    display.drawStr(x,y,icon);
}

void drawTitle(int x,
               int y,
               const char* text)
{
    display.setFont(u8g2_font_logisoso20_tf);

    display.drawStr(x,y,text);
}