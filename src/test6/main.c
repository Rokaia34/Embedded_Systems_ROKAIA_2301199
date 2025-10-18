// Test 6: Sends characters '0' to '9' sequentially with 500ms delay in a continuous loop.
// Verifies UART transmission and correct sequential sending.
#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"

int main(void) {
    Uart_Init();
    while (1) {
        for (char c = '0'; c <= '9'; c++) {
            Uart_SendChar(c);
            _delay_ms(500);
        }
        Uart_SendString("\r\n", 2);
    }
} 
