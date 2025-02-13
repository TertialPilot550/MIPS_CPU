#include <stdio.h>

#include "MIPS_CPU.h"

// Size of memory
const int SIZE_IN_WORDS = 0xFFFF;

/**
 * Setting up the simulation
 */

int main() {

    int32_t res = copyBitField(0xFFFF, 30, 1);
    printf("res:%d", res);

    //simulation();
    return 0;
}



void simulation() {
    printf("Setting Up Simulation...\n");
    MemoryUnit* mem = create_MemoryUnit(SIZE_IN_WORDS);
    MIPS_CPU* cpu = create_cpu(mem);
    printf("Running...\n");
    //
    
    
    cpu_start(cpu);
    
    
    //
    printf("Ending Simulation.\n");

    destroy_MemoryUnit(mem);
    destroy_cpu(cpu);
}