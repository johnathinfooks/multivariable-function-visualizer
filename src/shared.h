
#ifndef RENDER_H
#define RENDER_H

#include <stdint.h>
#include <stdio.h>
#include <math.h>

// types and declarations

#define RESOLUTION 32 // RES by RES sized square of slots
#define TABLE_SIZE (RESOLUTION * RESOLUTION)

typedef enum {
    light_green = 0,
    green = 1,
    light_yellow = 2,
    yellow = 3,
    light_orange = 4,
    orange = 5,
    light_red = 6,
    red = 7
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

// functions

int print_table(Table table);
Table calculate_table(double xmin, double xmax, double ymin, double ymax);

#endif // RENDER
