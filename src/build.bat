c:\"Program Files (x86)"\NASM\nasm.exe -f elf32 Boot.asm -o boot.o
C:\MinGW\bin\gcc.exe -m32 -c kernel.c -o kernel.o
C:\MinGW\bin\gcc.exe -m32 -c Keyboard.c -o Keyboard.o
C:\MinGW\bin\gcc.exe -m32 -c Source.c -o Source.o
C:\MinGW\bin\ld.exe -m i386 -T linker.ld -o kernel boot.o kernel.o Keyboard.o Source.o