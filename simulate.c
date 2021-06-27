#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#define MEMORY_SIZE 4294967296
// Memory layout
#define PRGM_TXT_START 0x00400000
#define PRGM_TXT_END 0x0fffffff

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

// Program counter
uint32_t PC = 0;

uint32_t fetch() {

}

int main(void) { 
    // Instruction cycle: 
    // 1. Fetch instruction from memory
    // 2. Decode instruction into it's corresponding opcode
    // 3. Execute instruction.
    // 4. Repeat



    return 0; 
}

