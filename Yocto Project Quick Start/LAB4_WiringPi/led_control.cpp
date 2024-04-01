#include <iostream>
#include <wiringPi.h>

#define LED_PIN 18 // GPIO pin connected to the LED

int main(void) {
    int brightness = 0; // Initialize brightness to 0

    // Initialize WiringPi library
    if (wiringPiSetupGpio() == -1) {
        std::cerr << "Error initializing WiringPi" << std::endl;
        return 1;
    }

    // Set the LED pin as PWM output
    pinMode(LED_PIN, PWM_OUTPUT);

    // Main loop
    while (1) {
        // Increase brightness (fade in)
        for (brightness = 0; brightness <= 1023; brightness++) {
            pwmWrite(LED_PIN, brightness);
            delay(5); // Delay for smooth transition
        }

        // Decrease brightness (fade out)
        for (brightness = 1023; brightness >= 0; brightness--) {
            pwmWrite(LED_PIN, brightness);
            delay(5); // Delay for smooth transition
        }
    }

    return 0;
}

