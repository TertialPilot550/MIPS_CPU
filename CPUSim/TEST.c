#include <stdio.h>
#include "Memory.h"



void MEM_TEST() {

    MemoryUnit* mem = create_MemoryUnit(0xFFFF);
    int size = m_getAddressSpace(mem);
    printf("SIZE: %x\n", size);

    m_writeWord(mem, 0, 0xFFFF);
    printf("Expected: 0xFFFF. Actual: %x\n", m_readWord(mem, 0));
   
    m_writeWord(mem, 0, 0x0);
    m_writeWord(mem, 1, 0xAAFF);
    printf("Expected: 0. Actual: %x\n", m_readWord(mem, 0));
    printf("Expected: 0xAAFF. Actual: %x\n", m_readWord(mem, 1));



}

int main() {
    MEM_TEST();
    return 0;

}