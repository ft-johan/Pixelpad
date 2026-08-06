#pragma once

void initDisplay();

void clearDisplay();

void updateDisplay();

void drawCenteredText(int y, const char* text);

void drawSmallCenteredAt(int y, const char* text);

void drawProgressBar(int blocks);