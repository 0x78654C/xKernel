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
ld -m elf_i386 -T link.ld -o kernel boot.o kernel.o keyboard.o -z noexecstack 

echo "[+] Opening in qemu..."
qemu-system-i386 -kernel kernel

echo "[+] Cleaning objects"
rm boot.o
rm keyboard.o
rm kernel.o
rm kernel