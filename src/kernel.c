/*
 *
 * kernel.c - version 0.0.1
 * 
 */
#include "keyboard.h"


#define WHITE_TXT 0x07 /* light gray on black text */

void clear_screen();
unsigned int x_printf(char *message, unsigned int line);
unsigned short* terminal_buffer1;
unsigned int vga_index1;


/* simple kernel written in C */
void main() 
{
	terminal_buffer1 = (unsigned short*)VGA_ADDRESS;
	clear_screen();
	print_string("Hello, world! Welcome to my xKernel.", YELLOW);
	vga_index1 = 80;
    while (1) {
        keyboard_handler();
    }
};

/* clear_screen : to clear the entire text screen */
void clear_screen()
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vidmem[i]=' ';
		i++;
		vidmem[i]=WHITE_TXT;
		i++;
	};
};

void print_string(char* str, unsigned char color)
{
    int index = 0;
    while (str[index]) {
        terminal_buffer1[vga_index1] = (unsigned short)str[index] | (unsigned short)color << 8;
        index++;
        vga_index1++;
    }
}

/* x_printf : the message and the line # */
unsigned int x_printf(char *message, unsigned int line)
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;

	i=(line*80*2);

	while(*message!=0)
	{
		if(*message=='\n') // check for a new line
		{
			line++;
			i=(line*80*2);
			*message++;
		} else {
			vidmem[i]=*message;
			*message++;
			i++;
			vidmem[i]=WHITE_TXT;
			i++;
		};
	};

	return(1);
}
