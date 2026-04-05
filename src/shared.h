
#ifndef RENDER_H
#define RENDER_H

#include <stdint.h>
#include <stdio.h>
#include <math.h>

// TYPES AND DECLARATIONS

#define RESOLUTION 511 // RES by RES sized square of slots; max resolution is 511
#define TABLE_SIZE (RESOLUTION * RESOLUTION)

typedef enum {
    pale_blue     = 0,
    light_blue    = 1,
    blue          = 2,
    bright_blue   = 3,
    bright_cyan   = 4,
    light_cyan    = 5,
    cyan          = 6,
    teal          = 7,
    light_green   = 8,
    green         = 9,
    yellow_green  = 10,
    light_yellow  = 11,
    yellow        = 12,
    orange        = 13,
    light_red     = 14,
    red           = 15
} ColorIntensity;

typedef struct {
    ColorIntensity color;
    double value;
} Cell;

typedef struct {
    double min_val;
    double max_val;

    Cell slot[TABLE_SIZE];
} Table;

typedef double (*Function)(double x, double y);

// FUNCTIONS

// render

int assign_color_intensity(Table *t);
int print_table_intensity(Table table);
int print_table_value(Table table);
int print_table_color(Table t);

// vmath

Table calculate_table(Function f, double xmin, double xmax, double ymin, double ymax);
double f_sine_wave(double x, double y);
double f_paraboloid(double x, double y);
double f_saddle(double x, double y);



#endif // RENDER
