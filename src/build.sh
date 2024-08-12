#!/bin/bash

echo "[+] Building Bootloader..."
nasm -f elf32 kernel.asm -o boot.o

echo "[+] Building Keyboard driver..."
gcc -m32 -c keyboard.c -o keyboard.o

#echo "[+] Building Source ..."
#gcc -m32 -c source.c -o source.o

echo "[+] Building Kernel..."
gcc -m32 -c kernel.c -o kernel.o

echo "[+] Linking..."
ld -m elf_i386 -T link.ld -o kernel boot.o kernel.o keyboard.o

echo "[+] Running..."
qemu-system-i386 -kernel kernel
