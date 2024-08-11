<<<<<<< HEAD
;;kernel.asm
bits 32         ;nasm directive - 32 bit
global entry
extern main            ;kmain is defined in the c file

section .text
entry:  jmp start

        ;multiboot spec
        align 4
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd -(0x1BADB002 + 0x00)  ;checksum. m+f+c should be zero

start:
        cli           ;block interrupts
        mov esp, stack_space  ;set stack pointer
        call main
        hlt           ;halt the CPU

section .bss
resb 8192       ;8KB for stack
stack_space:
=======
bits 32		;nasm directive
section .text
	;multiboot spec
	align 4
	dd 0x1BADB002			;magic
	dd 0x00				;flags
	dd - (0x1BADB002 + 0x00)	;checksum. m+f+c should be zero

global start
extern main	;main is defined in the kernel.c file

start:
	cli  ; stop interrupts

	call main

	hlt ; halt the CPU
>>>>>>> 136e6bb (new updates)
