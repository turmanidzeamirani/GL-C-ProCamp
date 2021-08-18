#include "Geometry.h"
#include <math.h>


void rectangle_calc(uint32_t height_meter, uint32_t width_meter, RectangleInch_t *out_data)
{
    out_data->height = METER_TO_INCH(height_meter);
    out_data->width = METER_TO_INCH(width_meter);
    out_data->area = (double)(out_data->height * out_data->width);
    out_data->perimeter = (double)(out_data->height + out_data->height + out_data->width + out_data->width);
}


void circle_calc(uint32_t radius, Circle_t *circle_data)
{
    circle_data->radius = radius;
    circle_data->perimeter = 2 * M_PI * circle_data->radius;
    circle_data->area = 2 * M_PI * circle_data->radius * circle_data->radius;
}


int factorial_10(void)
{
    int fact = 1;

    for (uint8_t i = 1; i <= 10; i++) {
        fact *= i;
    }

    return fact;
}