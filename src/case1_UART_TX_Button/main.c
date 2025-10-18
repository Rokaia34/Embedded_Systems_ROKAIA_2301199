#define F_CPU 16000000UL          // Set CPU frequency to 16 MHz
#include <avr/io.h>               // Include AVR I/O definitions
#include <util/delay.h>           // Include delay functions
#include <stdbool.h>              // Include boolean type (true/false)
#include "UART.h"                 // Include UART functions

int main(void) {
    DDRD &= ~(1 << PD2);          // Set PD2 (button) as input
    PORTD |= (1 << PD2);          // Enable pull-up resistor on PD2
    Uart_Init();                  // Initialize UART communication

    bool lastState = 1;           // Store previous button state

    while (1) {
        bool currentState = (PIND & (1 << PD2));  // Read current button state

        if (currentState != lastState) {          // If button state changed
            _delay_ms(50);                        // Wait 50ms to debounce

            if (!(PIND & (1 << PD2))) {           // If button released
                char msg[] = "button_released\r\n";
                Uart_SendString(msg, sizeof(msg)); // Send message via UART
            } else {                              // If button pressed
                char msg[] = "button_pressed\r\n";
                Uart_SendString(msg, sizeof(msg)); // Send message via UART
            }

            lastState = currentState;             // Update last state
        }
    }
}
