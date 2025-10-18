#if !defined(__AVR_ATmega328P__)
#include <avr/iom328p.h>
#endif

#include <avr/io.h>
#include "UART.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

void Uart_Init(void) {
    Uart_SetBaudRate(9600);
    UCSR0B = (1 << TXEN0) | (1 << RXEN0); // Enable TX & RX
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data bits, 1 stop bit
}

void Uart_SetBaudRate(unsigned short BaudRate) {
    unsigned short UBBR = ((F_CPU / 16) / BaudRate) - 1;
    UBRR0L = (UBBR & 0xFF);
    UBRR0H = ((UBBR >> 8) & 0xFF);
}

void Uart_SendChar(unsigned char DataByte) {
    while (!(UCSR0A & (1 << UDRE0))); // Wait for buffer to be empty
    UDR0 = DataByte;
}

unsigned char Uart_ReadData(void) {
    while (!(UCSR0A & (1 << RXC0))); // Wait for received data
    return UDR0;
}

void Uart_SendString(char DataString[], unsigned char Size) {
    for (unsigned char i = 0; DataString[i] && i < Size; i++) {
        Uart_SendChar(DataString[i]);
    }
}