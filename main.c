#include <stdio.h>
#include <stdbool.h>
#include "./wiring.h"

const int MAX_BLINK_TIMES = 20;
const int GREEN_LED_PIN = 7;
const int BLUE_LED_PIN = 22;

int main(int argc, char *argv[])
{
    int blinkNumber = 0;

    setupWiringPi();
    setPinMode(BLUE_LED_PIN, OUTPUT);
    setPinMode(GREEN_LED_PIN, OUTPUT);

    while (MAX_BLINK_TIMES > blinkNumber++)
    {
        printf("[Device] #%d Blue LED \n", blinkNumber);
        writeToPin(BLUE_LED_PIN, HIGH);
        wait(100);
        writeToPin(BLUE_LED_PIN, LOW);
        printf("[Device] #%d Green LED \n", blinkNumber);
        writeToPin(GREEN_LED_PIN, HIGH);
        wait(100);
        writeToPin(GREEN_LED_PIN, LOW);
    }

    return 0;
}
