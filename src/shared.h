#ifndef SHARED_H
#define SHARED_H

#include <stdint.h>
#include <stdio.h>
#include <math.h>

// TYPES AND DECLARATIONS

#define RESOLUTION 64 // RES by RES sized square of slots; max resolution is 511
#define TABLE_SIZE (RESOLUTION * RESOLUTION)

typedef enum {
    c0  = 0,
    c1  = 1,
    c2  = 2,
    c3  = 3,
    c4  = 4,
    c5  = 5,
    c6  = 6,
    c7  = 7,
    c8  = 8,
    c9  = 9,
    c10 = 10,
    c11 = 11,
    c12 = 12,
    c13 = 13,
    c14 = 14,
    c15 = 15
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
double f_ripple(double x, double y);
double f_peaks(double x, double y);
double f_checkerboard(double x, double y);
double f_cone(double x, double y);
double f_twisted(double x, double y);
double f_cross_waves(double x, double y);
double f_spiral(double x, double y);
double f_egg_carton(double x, double y);
double f_hyperbolic(double x, double y);


// parse

void parse_input(char* eq_str_b, int size_eq_str_b, char* res_str_b, int size_res_str_b);

#endif // SHARED_H
