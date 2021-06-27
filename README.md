# SAM - (S)imulator and (A)ssembler for (M)IPS

## MIPS Architecture

MIPS is a 32-bit RISC ISA. The MIPS computer has 32 general-purpose registers 
and can address 4GB of memory (2^32 bytes).

### Register usage

MIPS uses 32 32-bit general-purpose registers.

| Register Number | Register Name | Function                                                | 
| ---             | ---           | ---                                                     |
| $0              | $zero         | Hard-wired to 0                                         | 
| $1              | $at           | Assembler temporary, reserved for pseudo-instructions   | 
| $2 - $3         | $v0, $v1      | Function return values                                  |
| $4 - $7         | $a0 - $a3     | Function parameters, not preserved by sub-programs      | 
| $8 - $15        | $t0 - $t7     | Temporary data, not preserved by subprograms            | 
| $16 - $23       | $s0 - $s7     | Saved registers, preserved by subprograms               | 
| $24 - $25       | $t8, $t9      | Temporary data, not preserved by subprograms            |
| $26 - $27       | $k0, $k1      | Reserved for interrupt handle. Not for programmmer use. |
| $28             | $gp           | Global Area Pointer (base of global data segment)       | 
| $29             | $sp           | Stack Pointer                                           | 
| $30             | $fp           | Frame Pointer                                           | 
| $31             | $ra           | Return Address                                          | 

### Memory Layout

Reserved    : 0xffff 0010 -> 0xffff ffff -

MMIO        : 0xffff 0000 -> 0xffff 000f |  Kernel Level

Kernel Data : 0x9000 0000 -> 0xfffe ffff | 

Kernel Text : 0x8000 0000 -> 0x8fff ffff -

Stack       : 0x7fff ffff                -

                    |                    |

                    v                    | 

                                         |  

                    ^                    |  User Level 

                    |                    | 

Dynamic Data: 0x1000 8000                | 

Static Data : 0x1000 0000 -> 0x1000 7fff | 

Program Text: 0x0040 0000 -> 0x0fff ffff - 

Reserved    : 0x0000 0000 -> 0x003f ffff -  Kernel Level




