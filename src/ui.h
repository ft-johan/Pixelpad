#pragma once

void showHomeScreen(const char* title,
                    const char* icon);

void showFeedbackScreen(const char* title,
                        const char* icon);
void showBootLogo();

void showLoadingScreen(int progress);

void showReadyScreen();