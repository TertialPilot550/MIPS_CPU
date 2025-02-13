#ifndef MIPS_ISA_H
#define MIPS_ISA_H

#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "Memory.h"

/**
 *  Simple function based implementation of the mips system.
 */

// REGISTER NAMES
#define r_zero 0
#define r_at 1
// Results
#define r_v0 2
#define r_v1 3
// Arguments
#define r_a0 4
#define r_a1 5
#define r_a2 6
#define r_a3 7
// Temporaries
#define r_t0 8
#define r_t1 9
#define r_t2 10
#define r_t3 11
#define r_t4 12
#define r_t5 13
#define r_t6 14
#define r_t7 15
// Saved Temporaries
#define r_s0 16
#define r_s1 17
#define r_s2 18
#define r_s3 19
#define r_s4 20
#define r_s5 21
#define r_s6 22
#define r_s7 23

// More temporaries
#define r_t8 24
#define r_t9 25

// Reserved for kernel
#define r_k0 26
#define r_k1 27

// System
#define r_gp 28
#define r_sp 29
#define r_fp 30
#define r_ra 31

// Registers
typedef int32_t Register;


// Mips CPU register struct
struct MIPS_CPU {
    Register PC; // Program counter
    Register registers [32]; // Other registers
    MemoryUnit* mem; // program memory
};
typedef struct MIPS_CPU MIPS_CPU;

int32_t copyBitField(int32_t src, int sInd, int eInd);

MIPS_CPU* create_cpu(MemoryUnit* mem);
void destroy_cpu(MIPS_CPU* toFree);
void cpu_start(MIPS_CPU* cpu);
bool cpu_execute(MIPS_CPU* cpu, int32_t instruction);



#endif