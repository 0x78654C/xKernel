#ifndef KEYBOARD_DOT_H    /* This is an "include guard" */
#define KEYBOARD_DOT_H 
#define KEYBOARD_PORT 0x60
#define VGA_ADDRESS 0xB8000   
#define BLACK 0
#define GREEN 2
#define RED 4
#define YELLOW 14
#define WHITE_COLOR 15

unsigned char get_scancode();
void keyboard_handler();

extern unsigned short* terminal_buffer;
extern unsigned int vga_index;

void print_string(char* str, unsigned char color);
void print_char(char str, unsigned char color);
void clear_screen(void);

#endif