# SAM - (S)imulator and (A)ssembler for (M)IPS

## MIPS Architecture

# Register usage

MIPS uses 32 32-bit general-purpose registers.

| Register Number | Register Name | Function | 
| ---             | ---           | ---      |
| $0              | $zero         | Hard-wired to 0 | 
| $1              | $at           | Assembler temporary, reserved for pseudo-instructions | 
| $2 - $3         | $v0, $v1      | Function return values |
| $4 - $7         | $a0 - $a3     | Function parameters, not preserved by sub-programs | 


