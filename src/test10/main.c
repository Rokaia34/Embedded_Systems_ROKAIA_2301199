// Test 10: Waits for UART command "led_off" and turns off LED PB0 (pin 8)
// Verifies reception, processing, and output control.
#include <avr/io.h>
#include <string.h>
#include "UART.h"

int main(void) {
    DDRB |= (1 << PB0);  // LED output
    Uart_Init();

    char buffer[10];
    unsigned char i = 0;

    while (1) {
        unsigned char data = Uart_ReadData();

        if (data == '\n' || data == '\r') {
            buffer[i] = '\0'; // end string

            if (strcmp(buffer, "led_off") == 0) {
                PORTB &= ~(1 << PB0);  // turn LED off
                char msg[] = "LED turned OFF\r\n";
                Uart_SendString(msg, sizeof(msg));
            }

            i = 0; // reset buffer
        } else if (i < sizeof(buffer) - 1) {
            buffer[i++] = data;
        }
    }
} 
