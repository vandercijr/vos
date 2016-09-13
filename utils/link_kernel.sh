ld -m elf_i386 -T ./utils/link.ld -o ./bin/kernel.bin ./compile/kernelasm.o ./compile/kernelc.o
