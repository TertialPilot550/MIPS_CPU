#ifndef MEMORY_H
#define MEMORY_H 

#include <stdint.h>
#include <stdlib.h>

/**
 * Memory Module of dynamic size
 * @sammc
 */

typedef int32_t word_address;
typedef struct MemoryUnit {

    int size_in_words;
    word_address* base_address; // divided into words

} MemoryUnit;

MemoryUnit* create_MemoryUnit(int size_in_words) {
    MemoryUnit* mem = (MemoryUnit*) malloc(sizeof(mem));
    mem->size_in_words = size_in_words;
    mem->base_address = (word_address*) malloc(sizeof(word_address) * size_in_words);
    return mem;
}

void destroy_MemoryUnit(MemoryUnit* mem) {
    free(mem->base_address);
    free(mem);
}

int m_getAddressSpace(MemoryUnit* mem) {
    return mem->size_in_words;
}

void m_writeWord(MemoryUnit* mem, word_address address, int word) {
    *(mem->base_address + address) = word;
}

int m_readWord(MemoryUnit* mem, int address) {
    return *(mem->base_address + address);
}

// offset of zero means the lsb, up to offset 3
char m_readByte(MemoryUnit* mem, word_address address, int offset) {
    int res = *(mem->base_address + address);

    if (offset > 3) {
        return 0; // outside legal range of bytes
    }

    res >>= (offset * 8); // shift the requested byte to be the lsb
    res &= 0xFF; // just the last byte
    return (char) res;
}

#endif