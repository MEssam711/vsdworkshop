# RISC-V (32 bits) Instruction Set Architecture

RISC-V is an open-source Instruction Set Architecture (ISA) designed to be simple, efficient, and extensible. The 32-bit version, known as RV32, supports a 32-bit address space and includes a base integer instruction set (RV32I), which is essential for most general-purpose computing tasks. RV32 is modular, allowing additional extensions like floating-point operations (RV32F), atomic operations (RV32A), and more. Its simplicity and open nature make it ideal for educational purposes, research, and custom hardware implementations, fostering innovation and collaboration in the field of computer architecture. 

## Base Instruction Formats

RISC-V's 32-bit ISA includes four main instruction types: R, I, S, and U, which are aligned on a 4-byte (32-bit) boundary. This alignment relaxes to a 16-bit boundary with 16-bit extensions, but misalignment causes an address misaligned exception. Source (rs) and destination (rd) registers are consistently placed to simplify decoding. Additionally, there are B and J variants, which handle immediate values similarly to S and U instructions.

<img width="586" alt="image" src="https://github.com/user-attachments/assets/d2d3cb01-1ab8-4fe3-9b3e-2297c009e1c7">

### Immediate Encoding Variants

In 'B' (Branch) instructions, the immediate value is effectively 13 bits, but the least significant bit (LSB) is always zero, so it isn't stored in the instruction. For actual use, the LSB is needed, and left-shifting the 12-bit immediate restores the original 13-bit number. To avoid the expense of actual shifting, RISC-V stores a rearranged version of the shifted value. This method ensures the bit order of the immediate is mostly consistent between S and B types, simplifying decoding. Similarly, U and J types use shifted immediates, with J immediates rearranged to optimize overlap and reduce fanout and mux costs by about 50%.

<img width="696" alt="image" src="https://github.com/user-attachments/assets/f0ba095a-6179-4add-9fea-470ee2a3b3c2">

# References
1) https://github.com/riscv/riscv-isa-manual/releases/tag/20240411
2) https://en.wikipedia.org/wiki/RISC-V
3) https://varshaaks.wordpress.com/2021/07/19/rv32i-base-integer-instruction-set/
4) https://chatgpt.com/

