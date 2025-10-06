#include <stdint.h>

#define UART_BASE 0x04000040
#define UART_TX   ((volatile uint32_t *)(UART_BASE + 0x00))
#define UART_STAT ((volatile uint32_t *)(UART_BASE + 0x04))

void uart_putc(char c) {
    while (!(*UART_STAT & 1));
    *UART_TX = c;
}

void uart_puts(const char *s) {
    while (*s) uart_putc(*s++);
}

