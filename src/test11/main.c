// Test 11: Sends a wrong/invalid command that doesn’t match any allowed commands in code (led_on or led_off).
// Confirms proper error handling by checking that "Invalid command" is sent back.
#include <avr/io.h>
#include <string.h>
#include "UART.h"

int main(void) {
    Uart_Init();

    char buffer[20];
    unsigned char i = 0;

    while (1) {
        unsigned char data = Uart_ReadData();

        if (data == '\n') {
            buffer[i] = '\0';

            if (strcmp(buffer, "led_on") != 0 && strcmp(buffer, "led_off") != 0) {
                char msg[] = "Unknown command\r\n";
                Uart_SendString(msg, sizeof(msg));
            }

            i = 0;
        } 
        else if (i < sizeof(buffer) - 1) {
            buffer[i++] = data;
        }
    }
}
