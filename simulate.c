#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define MEMORY_SIZE 4294967296
// ----------------------------------------------------------------------------
// Memory layout
// ----------------------------------------------------------------------------
#define PRGM_TXT_START 0x00400000
#define PRGM_TXT_END 0x0fffffff

// ----------------------------------------------------------------------------
// Utility functions
// ----------------------------------------------------------------------------

//
// Returns the bits in the range [start, stop] of a uint32_t.
//
static inline uint32_t get_bits(uint32_t x, uint8_t start, uint8_t end) {
    uint64_t mask = ((uint64_t)1 << (end - start + 1)) - 1;
    return (x >> start) & mask;
}

// Memory
uint8_t MEM[MEMORY_SIZE] = {0};

// Registers names
enum register_names {
    zero,
    at,
    v0,
    v1,
    a0,
    a1,
    a2,
    a3,
    t0,
    t1,
    t2,
    t3,
    t4,
    t5,
    t6,
    t7,
    s0,
    s1,
    s2,
    s3,
    s4,
    s5,
    s6,
    s7,
    t8,
    t9,
    k0,
    k1,
    gp,
    sp,
    fp,
    ra
};

// Register file
uint32_t REGS[32] = {0};

//
// Fetches the machine code instruction pointed to by the program counter.
//
// Data is layed out in little endian byte order:
// 4|        | <-- PC + 4 (next instruction)
// 3|  MSBs  |
// 2|xxxxxxxx|
// 1|xxxxxxxx|
// 0|  LSBs  | <-- PC
//
static inline uint32_t fetch_instruction(uint32_t PC) {
    // Instructions are 32 bits wide, but the memory is byte addressable.
    // Casting the u8 pointer into memory to u32 fetches the 4 bytes we need.
    return *((uint32_t *)(MEM + PC));
}

int main(void) {
    // Instruction cycle:
    // 1. Fetch instruction from memory
    // 2. Decode instruction into it's corresponding opcode
    // 3. Execute instruction.
    // 4. Increment PC to point to next instruction in memory

    // Initialize program counter to point to beginning of text segment
    uint32_t PC = PRGM_TXT_START;

    MEM[PRGM_TXT_START] = 0xff;
    MEM[PRGM_TXT_START + 1] = 0xa5;
    MEM[PRGM_TXT_START + 2] = 0xb7;
    MEM[PRGM_TXT_START + 3] = 0x98;

    uint32_t instruction = fetch_instruction(PC);

    uint32_t bits = get_bits(instruction, 0, 31);
    printf("%x\n", bits);

    return 0;
}
