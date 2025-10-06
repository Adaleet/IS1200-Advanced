#include <stdint.h> 
/* main.c

   This file written 2024 by Artur Podobas and Pedro Antunes

   For copyright and licensing, see file COPYING */


/* Below functions are external and found in other files. */
extern void delay(int);
extern void print(const char*);
extern void print_dec(unsigned int);
extern void uart_putc(char c);
extern void uart_puts(const char *s);


int mytime = 0x5957;
char textstring[] = "text, more text, and even more text!";

/* Below is the function that will be called when an interrupt is triggered. */
void handle_interrupt(unsigned cause) 
{}

/* Add your code here for initializing interrupts. */
void labinit(void)
{}

void setdisplays(int displaynumber, int value) {
    volatile int* display_addr = (volatile int*)( (uintptr_t)0x04000050 + displaynumber * 0x10 );
    *display_addr = value;
}


int getbtn(void) {
    volatile int* btn_addr = (volatile int*) 0x040000d0;
    return *btn_addr & 1;
}


/* Your code goes into main as well as any needed functions. */
int main() {
    int display_value = 0;
    int last_btn_state = 0;

    labinit();
        // Print instructions
    print("=== Encryption Demo ===\r\n");
    print("Use the first switch to toggle between Encrypt/Decrypt.\r\n");
    print("Use the button to cycle between algorithms (1–4):\r\n");
    print("1 = Caesar Cipher\r\n");
    print("2 = XOR Encryption\r\n");
    print("3 = [Reserved]\r\n");
    print("4 = [Reserved]\r\n");
    print("========================\r\n");


    while (1) {
      
        int btn_state = getbtn();
        if (btn_state && !last_btn_state) { // Detect rising edge (just pressed)
            display_value = (display_value + 1) % 10; // Example: loop 0-9
            setdisplays(0, display_value); // Update display 0
        }
        last_btn_state = btn_state;
        delay(10); // Small delay to debounce the button
    }
}




