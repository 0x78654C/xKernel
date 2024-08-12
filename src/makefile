hellomake:
	nasm -f elf32 boot.asm -o boot.o
	gcc -m32 -c kernel.c -o kernel.o
	gcc -m32 -c Keyboard.c -o Keyboard.o
	gcc -m32 -c Source.c -o Source.o
	ld -m i386 -T linker.ld -o kernel boot.o kernel.o Keyboard.o Source.o