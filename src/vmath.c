#include "shared.h"

double f_sine_wave(double x, double y) { return sin(x) * cos(y); }

double f_paraboloid(double x, double y) { return x * x + y * y; }

double f_saddle(double x, double y) { return x * x - y * y; }

Table calculate_table(Function f, double xmin, double xmax, double ymin, double ymax)
{
    Table t;
    Cell c;

    for (int row = 0; row < RESOLUTION; row++) {
        for (int col = 0; col < RESOLUTION; col++) {
            // x and y are linear interpolations; turning the index values into ranges
            double x = xmin + col * (xmax - xmin) / (RESOLUTION - 1); // second part is step size
            double y = ymax - row * (ymax - ymin) / (RESOLUTION - 1);
            c.value = f(x, y);
            t.slot[RESOLUTION * row + col] = c;
        }
    }
    return t;
}
