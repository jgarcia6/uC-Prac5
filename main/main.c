/* Reaction time game */
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "my_gpio.h"

#define LED_GPIO    eGpioNum2
#define BTN_GPIO    eGpioNum4

// Enumerations
typedef enum ButtonState_tag
{
    eBtnUndefined = 0,
    eBtnShortPressed,
    eBtnLongPressed
} eButtonState_t;

typedef enum PlayerInputState_tag
{
    eWaiting = 0,
    eCorrect,
    eIncorrect
} ePlayerInputState_t;

typedef enum ButtonId_tag
{
    eButtonId0 = 0,
    eButtonId1,
    eButtonId2,
    eButtonId3,
    eMaxButtonId
} eButtonId_t;

typedef enum GameState_tag
{
    eGameRestart = 0,
    eWaitForStart,
    ePlayPattern,
    eWaitForPlayer,
    eYouWin,
    eYouLose
} eGameState_t;

#define MAX_LEVEL  8
#define NUM_OF_LEDS 4

// Global variable
uint32_t _millis;
uint8_t randomPattern[MAX_LEVEL];
uint8_t level;

static void initIO(void)
{
    // FIXME:
    // Replace the following code and insert
    // code to initialize all IO pins for the assigment
    gpio_init(LED_GPIO, eOutput);
    gpio_init(BTN_GPIO, eInput);

}

bool playSequence(eGameState_t gameState)
{
    // FIXME:
    // Playback the corresponding animation of the gameState parameter
    // Once playback has finished, return true, otherwise return false
    gpio_write(LED_GPIO, (gpio_read(BTN_GPIO) == eLow)? eHigh : eLow); 
    return true;
}

eButtonState_t checkButtons(eButtonId_t *buttonNumber)
{
    // FIXME:
    // Polls each button and returns the press state and the corresponding button
    *buttonNumber = eMaxButtonId;
    return eBtnUndefined;
}

ePlayerInputState_t checkPlayerInput(eButtonState_t buttonState, eButtonId_t buttonId)
{
    // FIXME:
    // Waits for player input and verifies that it is matching the pattern
    return eWaiting;
}

void delayMs(uint16_t ms)
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}

int app_main(void)
{
    eGameState_t  currentGameState = eGameRestart;
    ePlayerInputState_t playerInputState;
    eButtonId_t buttonId;
    eButtonState_t buttonState;

    initIO();

    while(1)
    {   
        buttonState = checkButtons(&buttonId);
        
        if (buttonState == eBtnLongPressed)
            currentGameState = eGameRestart;

        switch(currentGameState)
        {
            case eGameRestart:
                for (uint8_t idx = 0; idx < MAX_LEVEL; idx++ )
                {
                    randomPattern[idx] = esp_random() & (NUM_OF_LEDS - 1);
                }
                level = 0;
                currentGameState++;
                break;

            case eWaitForStart:
                playSequence(eWaitForStart);
                if (buttonState == eBtnShortPressed)
                    currentGameState++;
                break;

            case ePlayPattern:
                if (!playSequence(ePlayPattern))
                    currentGameState++;
                break;

            case eWaitForPlayer:
                playSequence(eWaitForPlayer);
                playerInputState = checkPlayerInput(buttonState, buttonId);
                if (playerInputState == eCorrect)
                {
                    level++;
                    if (level < MAX_LEVEL)
                    {
                        currentGameState = ePlayPattern;
                    }
                    else
                    {
                        currentGameState = eYouWin;
                    }
                }
                else if (playerInputState == eIncorrect)
                {
                    currentGameState = eYouLose;
                }
                break;
            case eYouLose:
            case eYouWin:
                if (!playSequence(currentGameState))
                    currentGameState = eGameRestart;
                break;
        }
        delayMs(1);
        _millis++;
    }
}