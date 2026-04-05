#include "shared.h"

double f_sine_wave(double x, double y) { return sin(x) * cos(y); }

double f_paraboloid(double x, double y) { return x * x + y * y; }

double f_saddle(double x, double y) { return x * x - y * y; }

Table calculate_table(Function f, double xmin, double xmax, double ymin, double ymax)
{
    for (int row = 0; row < RESOLUTION; row++) {
        for (int col = 0; col < RESOLUTION; col++) {

        }
    }
}
