#include <stdint.h>
#include <stdio.h>
#include "EndianessSwap.h"
#include "RgbConverter.h"
#include "Geometry.h"

U16_t little_16 = { .raw = { 0xCD, 0xEF} };
U16_t big_16;

U32_t little_32 = { .raw = { 0x89, 0xAB, 0xCD, 0xEF} };
U32_t big_32;

U64_t little_64 = { .raw = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF} };
U64_t big_64;

int main(void)
{
    // 2) ==============================================================================================================================
    printf("\r\n\r\n----- Endianess swap test -----\r\n");
    printf("uint16_t -> Passed bytes:    %X %X\r\n", little_16.raw[0], little_16.raw[1]);
    big_16.val = EndiSwap16(little_16.val);
    printf("            Converted bytes: %X %X\r\n", big_16.raw[0], big_16.raw[1]);

    printf("uint32_t -> Passed bytes:    %X %X %X %X\r\n", little_32.raw[0], little_32.raw[1], little_32.raw[2], little_32.raw[3]);
    big_32.val = EndiSwap32(little_32.val);
    printf("            Converted bytes: %X %X %X %X\r\n", big_32.raw[0], big_32.raw[1], big_32.raw[2], big_32.raw[3]);

    printf("uint64_t -> Passed bytes:    %X %X %X %X %X %X %X %X\r\n", little_64.raw[0], little_64.raw[1], little_64.raw[2],\
                                                                        little_64.raw[3], little_64.raw[4], little_64.raw[5],\
                                                                        little_64.raw[6], little_64.raw[7]);
    big_64.val = EndiSwap64(little_64.val);
    printf("            Converted bytes: %X %X %X %X %X %X %X %X\r\n", big_64.raw[0], big_64.raw[1], big_64.raw[2], big_64.raw[3],\
                                                                        big_64.raw[4], big_64.raw[5], big_64.raw[6], big_64.raw[7]);

    // 3) ==============================================================================================================================
    printf("\r\n\r\n----- RGB888 to RGB565 test -----\r\n");
    uint32_t rgb888 = 0x1F9A2D;
    uint16_t expected = 0x1CC5;
    printf("Passed value: %X -> conversion expected: %X\r\n", rgb888,  expected);
    uint16_t converted = RGB888_to_RGB565(rgb888);
    if(converted == expected)
    {
        printf("        We got Expected value: %X\r\n", converted);
    }else
        {
            printf("        CONVERSION ERROR!!!(%X)", converted);            
        }
    
    // 4) ==============================================================================================================================
    printf("\r\n\r\n----- Rectangle calculation test -----\r\n");
    uint32_t height, width;
    RectangleInch_t rectangle;
    printf("Enter rectangle width:\r\n");
    scanf("%d", &width);
    printf("Enter rectangle height:\r\n");
    scanf("%d", &height);
    rectangle_calc(height, width, &rectangle);
    printf("Result:\r\nWidth - %.3f inches\r\nHeight - %.3f inches\r\nPerimeter - %.3f inches\r\nArea - %.3f inches\r\n", \
                                    rectangle.width, rectangle.height, rectangle.perimeter, rectangle.area);

    // 5) ==============================================================================================================================
    printf("\r\n\r\n----- Circle with radius 6 test -----\r\n");
    Circle_t circle;
    circle_calc(6, &circle);
    printf("Result:\r\nRadius - %d\r\nPerimeter - %.3f\r\nArea - %.3f\r\n", \
                                    circle.radius, circle.perimeter, circle.area);

    // 6) ==============================================================================================================================
    printf("\r\n\r\n----- Factorial of 10 test -----\r\n");
    printf("Result: %u\r\n", factorial_10());

    // 7) ==============================================================================================================================
    printf("\r\n\r\n----- Integer devisor -----\r\n");
    printf("Enter value which is bigger than '0' and less or equals to '500'\r\n");
    int devisor = 0;
    scanf("%d", &devisor);
    printf("Devisible values:\r\n");
    for(int k = 1; k <= 500; k++)
    {
        if((k % devisor) == 0)
        {
            printf(": % d\r\n", k);
        }
    }
    printf("\r\n\r\n----- Done -----\r\n");
    return 0;
}