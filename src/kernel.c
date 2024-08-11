/*
 *
 * kernel.c - version 0.0.1
 * 
 */
//#include "keyboard.h"


#define WHITE_TXT 0x07 /* light gray on black text */

void clear_screen();
unsigned int x_printf(char *message, unsigned int line);

/* simple kernel written in C */
void main() 
{
	clear_screen();
	x_printf("Hello, world! Welcome to my xKernel.", 0);
   // while (1) {
     //   keyboard_handler();
    //}
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
