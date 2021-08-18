#ifndef ENDIANESS_SWAP_H
#define ENDIANESS_SWAP_H

#include <stdint.h>


typedef union 
{
    uint16_t val;
    uint8_t  raw[sizeof(uint16_t)];
}U16_t;

typedef union 
{
    uint32_t val;
    uint8_t  raw[sizeof(uint32_t)];
}U32_t;

typedef union 
{
    uint64_t val;
    uint8_t  raw[sizeof(uint64_t)];
}U64_t;


uint16_t EndiSwap16(uint16_t in_var);
uint32_t EndiSwap32(uint32_t in_var);
uint64_t EndiSwap64(uint64_t in_var);

#endif // ENDIANESS_SWAP_H