// Test 7: Alternates sending "pressed" and "released" every 1 second to simulate a button press/release.
// Verifies UART transmission for changing states.
#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"
#include <stdbool.h>

int main(void) {
    Uart_Init();
    bool pressed = false;

    while (1) {
        if (pressed) {
            Uart_SendString("pressed\r\n", 9);
        } else {
            Uart_SendString("released\r\n", 10);
        }
        pressed = !pressed;
        _delay_ms(1000);
    }
} 
