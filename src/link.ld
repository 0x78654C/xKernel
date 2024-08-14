OUTPUT_FORMAT(elf32-i386)
ENTRY(main)
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