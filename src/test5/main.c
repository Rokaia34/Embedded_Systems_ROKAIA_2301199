// Test 5: Sends a string via UART once at microcontroller startup.
// Verifies correct one-time transmission functionality.
#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"

int main(void) {
    Uart_Init();
    Uart_SendString("System Ready\r\n", 14);
    while (1) { }
} 
