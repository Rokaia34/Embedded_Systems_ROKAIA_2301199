// Test 2: Tests UART by sending characters 'A' to 'Z' sequentially with 200ms delay.
// Verifies basic data transmission functionality and character-by-character sending.
#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"

int main(void) {
    Uart_Init();
    while (1) {
        for (char c = 'A'; c <= 'Z'; c++) {
            Uart_SendChar(c);
            _delay_ms(200);
        }
        Uart_SendString("\r\n", 2);
    }
}
