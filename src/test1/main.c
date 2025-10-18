// Test 1: This code tests UART transmission by repeatedly sending "Hello" every 1 second.
// It verifies that the UART is initialized correctly and data is transmitted continuously.

#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"

int main(void) {
    Uart_Init();
    while (1) {
        Uart_SendString("Hello\r\n", 7);
        _delay_ms(1000);
    }
}
