#include "MIPS_CPU.h"

// inclusive on both sides
int32_t copyBitField(int32_t src, int sInd, int eInd) {
    // 0x0000.0000
    src >>= eInd;

    // construct a bit string of the appropriate length
    int len = sInd - eInd;
    
    // 2^n - 1
    // Preserve the bits you mean too, clear the rest
    int res = ((int32_t) pow(2, len) - 1) & src;
    return res;
}

// opcode (31:26) Rs(25:21) Rt (20:16) Rd (15:11) shamt (10:6) funct (5:0)
bool processRType(MIPS_CPU* cpu, int32_t instruction) {
    return true;
}

// opcode (31:26) Rs(25:21) Rt (20:16) Immediate (15:0)
bool processIType(MIPS_CPU* cpu, int32_t instruction) {
    return true;
}

// opcode (31:26) address (25:0)
bool processJType(MIPS_CPU* cpu, int32_t instruction) {
    return true;
}

// returning false means the program should stop running, true it continues
bool cpu_execute(MIPS_CPU* cpu, int32_t instruction) {
    
    int32_t opcode = copyBitField(instruction, 31, 6);
    int32_t func = copyBitField(instruction, 5, 0);
   
    // determine type
    
    bool isRType = opcode == 0;
    if (isRType) {
        return processRType(cpu, instruction);
    }
    
    bool isJType = (opcode == 2 || opcode == 3);
    if (isJType) {
        return processJType(cpu, instruction);
    }

    bool isIType = opcode > 3;
    if (isIType) {
        return processIType(cpu, instruction);
    }

    // invalid instruction of some sort
    return false;
}


// Constructor for cpu object
MIPS_CPU* create_cpu(MemoryUnit* mem) {
    MIPS_CPU* cpu = (MIPS_CPU*) malloc(sizeof(*cpu));
    cpu->mem = mem;
    return cpu;
}

// Deconstructor
void destroy_cpu(MIPS_CPU* toFree) {
    free(toFree);
}

// Fetch Execute Loop. 
void cpu_start(MIPS_CPU* cpu) {
    bool running = true;
    while (running) {
        cpu->registers[0] = 0; // in case someone tries to write over register 0
        int instruction = m_readWord(cpu->mem, cpu->PC++); // fetch the instruction at the address of the pc
        running = cpu_execute(cpu, instruction);      // execute
    }
}

