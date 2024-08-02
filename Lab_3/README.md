# RISC-V (32 bits) Instruction Set Architecture

RISC-V is an open-source Instruction Set Architecture (ISA) designed to be simple, efficient, and extensible. The 32-bit version, known as RV32, supports a 32-bit address space and includes a base integer instruction set (RV32I), which is essential for most general-purpose computing tasks. RV32 is modular, allowing additional extensions like floating-point operations (RV32F), atomic operations (RV32A), and more. Its simplicity and open nature make it ideal for educational purposes, research, and custom hardware implementations, fostering innovation and collaboration in the field of computer architecture. 

## Base Instruction Formats

RISC-V's 32-bit ISA includes four main instruction types: R, I, S, and U, which are aligned on a 4-byte (32-bit) boundary. This alignment relaxes to a 16-bit boundary with 16-bit extensions, but misalignment causes an address misaligned exception. Source (rs) and destination (rd) registers are consistently placed to simplify decoding. Additionally, there are B and J variants, which handle immediate values similarly to S and U instructions.

<img width="586" alt="image" src="https://github.com/user-attachments/assets/d2d3cb01-1ab8-4fe3-9b3e-2297c009e1c7">

### Immediate Encoding Variants

In 'B' (Branch) instructions, the immediate value is effectively 13 bits, but the least significant bit (LSB) is always zero, so it isn't stored in the instruction. For actual use, the LSB is needed, and left-shifting the 12-bit immediate restores the original 13-bit number. To avoid the expense of actual shifting, RISC-V stores a rearranged version of the shifted value. This method ensures the bit order of the immediate is mostly consistent between S and B types, simplifying decoding. Similarly, U and J types use shifted immediates, with J immediates rearranged to optimize overlap and reduce fanout and mux costs by about 50%.

<img width="696" alt="image" src="https://github.com/user-attachments/assets/f0ba095a-6179-4add-9fea-470ee2a3b3c2">

#Unique RV32 Instructions
The below 15 instructions are from my updown_counter.c code using o1 option and they are extracted from the main part.
1)  addi    sp,sp,-112
2)  li      s2,0
3)  lui     s3,0x2b
4)  j       102f0 <main+0xfc>
5)  lbu     a5,15(sp)
6)  beq     a5,a4,102b0 <main+0xbc>
7)  bne     a5,a4,10300 <main+0x10c>
8)  jal     ra,107f8 <puts>
9)  ld      ra,104(sp)
10)  ret
11)  bnez    s2,10304 <main+0x110>
12)  beqz    s2,102f0 <main+0xfc>
13)  mv      s2,s1
14)  blt     a5,s0,102d4 <main+0xe0>
15)  bgez    s0,102e4 <main+0xf0>

## 32 Bit Pattern Encoding
1) 1111 1001 0000 0001 0000 0001 0001 0011
2) 0000 0000 0000 0000 0000 1001 0001 0011
3) 0000 0000 0000 0010 1011 1001 1011 0111
4) 0000 1010 0100 0000 0000 0000 0110 1111
5) 0000 1111 0001 0100 0111 1000 0011
6) 0000 0100 1110 0111 1000 1100 0110 0011
7) 0000 1000 1110 0111 1001 1100 0110 0011
8) 0101 1000 0100 0000 0000 0000 1110 1111
9) 0000 0110 1000 0001 0011 0000 1000 0011
10) 0000 0000 0000 0000 1000 0000 0110 0111
11) 0000 0100 0000 1001 0001 1010 0110 0011
12) 0000 0010 0000 1001 0000 1000 0110 0011
13) 0000 0000 0000 0100 1000 1001 0001 0011
14) 1111 1010 1000 0111 1100 1110 1110 0011
15) 1111 1100 0000 0100 0101 0100 1110 0011

# References
1) https://github.com/riscv/riscv-isa-manual/releases/tag/20240411
2) https://en.wikipedia.org/wiki/RISC-V
3) https://varshaaks.wordpress.com/2021/07/19/rv32i-base-integer-instruction-set/
4) https://chatgpt.com/

