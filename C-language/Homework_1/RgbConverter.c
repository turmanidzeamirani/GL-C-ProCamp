#include "RgbConverter.h"


uint16_t RGB888_to_RGB565(uint32_t rgb888)
{ 
    return (uint16_t)(((rgb888 >> 8) & 0b1111100000000000) | \
                        ((rgb888 >> 5) & 0b0000011111100000) | \
                        ((rgb888 >> 3) & 0b0000000000011111));
                        
}
