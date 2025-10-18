#define F_CPU 16000000UL          // Set CPU frequency to 16 MHz
#include <avr/io.h>               // Include AVR I/O definitions
#include <util/delay.h>           // Include delay functions
#include <string.h>               // Include string functions
#include "UART.h"                 // Include UART functions

int main(void) {
    DDRB |= (1 << PB0);           // Set PB0 (LED) as output
    Uart_Init();                  // Initialize UART communication

    char buffer[10];              // Buffer to store received command
    unsigned char i = 0;          // Index for buffer

    char startMsg[] = "Ready to receive commands...\r\n";
    Uart_SendString(startMsg, sizeof(startMsg));  // Send startup message

    while (1) {
        unsigned char data = Uart_ReadData();     // Read a byte from UART

        if (data == '\n' || data == '\r') {      // If end of command
            buffer[i] = '\0';                    // Terminate string

            if (strcmp(buffer, "led_on") == 0) {      // Check command
                PORTB |= (1 << PB0);                  // Turn LED ON
                char msg[] = "LED turned ON\r\n";
                Uart_SendString(msg, sizeof(msg));   // Send confirmation
            } else if (strcmp(buffer, "led_off") == 0) {
                PORTB &= ~(1 << PB0);                 // Turn LED OFF
                char msg[] = "LED turned OFF\r\n";
                Uart_SendString(msg, sizeof(msg));   // Send confirmation
            } else {
                char msg[] = "Unknown command\r\n";  // Invalid command
                Uart_SendString(msg, sizeof(msg));   // Notify user
            }

            i = 0;  // Reset buffer index for next command
        } else if (i < sizeof(buffer) - 1) {
            buffer[i++] = data;  // Store received byte in buffer
        }
    }
}
