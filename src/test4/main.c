// Test 4: Tests UART data processing by receiving a character, 
// adding one to its ASCII value, and sending it back.
// Verifies correct reception, modification, and transmission.
#include <avr/io.h>
#include "Uart.h"
#include <util/delay.h>

int main(void) {
    Uart_Init();
    while (1) {
        unsigned char c = Uart_ReadData();
        Uart_SendChar(c + 1);
        _delay_ms(500);
    }
}
