// Test 3: Tests UART reception and echo functionality.
// Receives a character from UART and immediately sends it back to verify bidirectional communication.
#include <avr/io.h>
#include "Uart.h"

int main(void) {
    Uart_Init();
    while (1) {
        unsigned char c = Uart_ReadData();
        Uart_SendChar(c);
    }
}
