#!/bin/bash

echo "[+] Building Bootloader..."
nasm -f elf32 kernel.asm -o boot.o

<<<<<<< HEAD
echo "[+] Building Keyboard driver..."
gcc -m32 -c keyboard.c -o keyboard.o
=======
#echo "[+] Building Keyboard driver..."
#gcc -m32 -c keyboard.c -o keyboard.o
>>>>>>> 136e6bb (new updates)

#echo "[+] Building Source ..."
#gcc -m32 -c source.c -o source.o

echo "[+] Building Kernel..."
gcc -m32 -c kernel.c -o kernel.o

echo "[+] Linking..."
<<<<<<< HEAD
ld -m elf_i386 -T link.ld -o kernel boot.o kernel.o keyboard.o
=======
ld -m elf_i386 -T link.ld -o kernel boot.o kernel.o
>>>>>>> 136e6bb (new updates)

echo "[+] Running..."
qemu-system-i386 -kernel kernel
