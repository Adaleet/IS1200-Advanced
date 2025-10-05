#include <stdint.h>

#define UART_BASE 0x10000000
#define UART_TX   ((volatile uint32_t *)(UART_BASE + 0x00))
#define UART_STAT ((volatile uint32_t *)(UART_BASE + 0x04))

void uart_putc(char c) {
    while (!(*UART_STAT & 1));
    *UART_TX = c;
}

void uart_puts(const char *s) {
    while (*s) uart_putc(*s++);
}

int main(void) {
    uart_puts("Hello from DTEK-V!\r\n");
    while (1);
    return 0;
}
