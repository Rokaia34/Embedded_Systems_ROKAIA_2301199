// Test 8: Tests UART transmission triggered by button press and release.
// Sends "button_pressed" and "button_released" to verify input detection and UART output.
#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"
#include <stdbool.h>

int main(void) {
    DDRD &= ~(1 << PD2);  // Input
    PORTD |= (1 << PD2);  // Pull-up resistor

    Uart_Init();

    bool lastState = 1;

    while (1) {
        bool currentState = (PIND & (1 << PD2));
        if (currentState != lastState) {
            _delay_ms(50);
            if (!(PIND & (1 << PD2))) {
                Uart_SendString("button_released\r\n", 17);
            } else {
                Uart_SendString("button_pressed\r\n", 18);
            }
            lastState = currentState;
        }
    }
} 
