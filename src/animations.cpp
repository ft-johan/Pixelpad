#include <Arduino.h>
#include "animations.h"
#include "ui.h"

enum BootState
{
    BOOT_BLACK,
    BOOT_LOGO,
    BOOT_LOADING,
    BOOT_READY,
    BOOT_DONE
};

static BootState state = BOOT_BLACK;

static unsigned long timer = 0;

void startBootAnimation()
{
    state = BOOT_BLACK;
    timer = millis();
}

bool bootAnimationFinished()
{
    return state == BOOT_DONE;
}

void updateBootAnimation()
{
    switch(state)
    {
        case BOOT_BLACK:

            if(millis() - timer > 200)
            {
                showBootLogo();

                timer = millis();

                state = BOOT_LOGO;
            }

            break;

        case BOOT_LOGO:

            if(millis() - timer > 500)
            {
                showLoadingScreen(0);

                timer = millis();

                state = BOOT_LOADING;
            }

            break;

        case BOOT_LOADING:

            static int progress = 0;

            if(millis() - timer > 120)
            {
                progress += 10;

                showLoadingScreen(progress);

                timer = millis();

                if(progress >= 100)
                {
                    showReadyScreen();

                    timer = millis();

                    state = BOOT_READY;
                }
            }

            break;

        case BOOT_READY:

            if(millis() - timer > 600)
            {
                state = BOOT_DONE;
            }

            break;

        default:
            break;
    }
}