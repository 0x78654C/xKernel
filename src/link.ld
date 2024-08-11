<<<<<<< HEAD
OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
 {
   . = 1M;
   .text BLOCK(4K) : ALIGN(4K)
   {
       *(.multiboot)
       *(.text)
   }
   .data : { *(.data) }
   .bss  : { *(.bss)  }
 }
=======
OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
{
	. = 0x100000;
	.text : {*(.text)}
	.data : {*(.data)}
	.bss  : {*(.bss)}
}
>>>>>>> 136e6bb (new updates)
