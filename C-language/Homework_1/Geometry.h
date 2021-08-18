#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdint.h>

#define METER_TO_INCH(x)    (float)((x) * 39.3701)

typedef struct
{
    float height;
    float width;
    double area;
    double perimeter;

}RectangleInch_t;

typedef struct
{
    uint32_t radius;
    float area;
    float perimeter;

}Circle_t;

void rectangle_calc(uint32_t height_meter, uint32_t width_meter, RectangleInch_t *out_data);
void circle_calc(uint32_t radius, Circle_t *circle_data);
int factorial_10(void);

#endif // GEOMETRY_H