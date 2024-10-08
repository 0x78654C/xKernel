#include "keyboard.h"  
#include <sys/io.h>
#include <stdio.h>

int clicked = 0;
int canSend = 0;
char ch = 0;
unsigned short* terminal_buffer;
unsigned int vga_index;

void print_char(char str, unsigned char color)
{
    terminal_buffer[vga_index-1] = str | (unsigned short)color << 8;
    vga_index++;
}


unsigned char get_scancode()
{
    unsigned char inputdata;
    inputdata = inb(0x60);
    return inputdata;
}

char get_input_keycode()
{
    ch =0;
    while ((ch =inb(KEYBOARD_PORT)) !=0){
        if(ch > 0)
            return ch;
    }
    return ch;
}
void keyboard_handler()
{
    unsigned char scancode;
    unsigned int shift_key = 0;

    canSend = 0;
    scancode = get_input_keycode();
    if(ch > 0)
    {
        if (scancode == 0x2A)
        {
            shift_key = 1;//Shift key is pressed
        }
        else if (scancode & 0xAA)
        {
            shift_key = 0;//Shift Key is not pressed
        }

        if (scancode & 0x80)
        {
            int shiftaltctrl = 1;//Put anything to see what special keys were pressed
        }
        else
        {
            char character;
            if (scancode == 0x0F) {
                clicked = 0; // tab, resets stuff
            //  clear_screen();
            }

            if (scancode == 0x01) {
                clicked = 0;
            }

            if (scancode == 0x1E && clicked == 0) {
            
                character = 'a';
                //clicked = 1
                canSend = 1;
            
            }
            if (scancode == 0x30 && clicked == 0) {

                character = 'b';
                //clicked = 1
                canSend = 1;

            }
            if (scancode == 0x2E && clicked == 0) {

                character = 'c';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x20 && clicked == 0) {

                character = 'd';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x12 && clicked == 0) {

                character = 'e';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x21 && clicked == 0) {

                character = 'f';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x22 && clicked == 0) {

                character = 'g';
                //clicked = 1
                canSend = 1;
            }

            if (scancode == 0x23 && clicked == 0) {

                character = 'h';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x17 && clicked == 0) {

                character = 'i';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x24 && clicked == 0) {

                character = 'j';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x25 && clicked == 0) {

                character = 'k';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x26 && clicked == 0) {

                character = 'l';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x32 && clicked == 0) {

                character = 'm';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x31 && clicked == 0) {

                character = 'n';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x18 && clicked == 0) {

                character = 'o';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x19 && clicked == 0) {

                character = 'p';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x10 && clicked == 0) {

                character = 'q';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x13 && clicked == 0) {

                character = 'r';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x1F && clicked == 0) {

                character = 's';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x14 && clicked == 0) {

                character = 't';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x16 && clicked == 0) {

                character = 'u';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x2F && clicked == 0) {

                character = 'v';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x11 && clicked == 0) {

                character = 'w';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x2D && clicked == 0) {

                character = 'x';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x15 && clicked == 0) {

                character = 'y';
                //clicked = 1
                canSend = 1;
            }
            if (scancode == 0x2c && clicked == 0) {

                character = 'z';
                //clicked = 1
                canSend = 1;
            }

            if (canSend == 1) {
                vga_index++;
                canSend = 0;
                clicked = 1;
                print_char(character, WHITE_COLOR);
            }
            ch = 0;
        }
    }
}

