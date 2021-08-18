#include "EndianessSwap.h"


uint16_t EndiSwap16(uint16_t in_var)
{
    U16_t in;
    U16_t out;

    in.val = in_var;
    // Since we know that uint16_t always 2 bytes
    out.raw[0] = in.raw[1];
    out.raw[1] = in.raw[0];

    return out.val;
}


uint32_t EndiSwap32(uint32_t in_var)
{
    U32_t in;
    U32_t out;

    in.val = in_var;
    // Since we know that uint32_t always 4 bytes
    out.raw[0] = in.raw[3];
    out.raw[1] = in.raw[2];
    out.raw[2] = in.raw[1];
    out.raw[3] = in.raw[0];

    return out.val;
}


uint64_t EndiSwap64(uint64_t in_var)
{
    U64_t in;
    U64_t out;

    in.val = in_var;
    // Since we know that uint32_t always 8 bytes
    out.raw[0] = in.raw[7];
    out.raw[1] = in.raw[6];
    out.raw[2] = in.raw[5];
    out.raw[3] = in.raw[4];
    out.raw[4] = in.raw[3];
    out.raw[5] = in.raw[2];
    out.raw[6] = in.raw[1];
    out.raw[7] = in.raw[0];

    return out.val;
}

