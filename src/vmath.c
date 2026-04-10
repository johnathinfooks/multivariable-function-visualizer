#include "shared.h"

// f(x, y) =

double f_sine_wave(double x, double y) { return sin(x) * cos(y); }
double f_paraboloid(double x, double y) { return x*x + y*y; }
double f_saddle(double x, double y) { return x*x - y*y; }
double f_ripple(double x, double y) { double r = sqrt(x*x + y*y); return r == 0 ? 1.0 : sin(r) / r; }
double f_peaks(double x, double y) { return 3*(1-x)*(1-x)*exp(-x*x - (y+1)*(y+1)) - 10*(x/5 - x*x*x - y*y*y*y*y)*exp(-x*x - y*y) - exp(-(x+1)*(x+1) - y*y)/3; }
double f_checkerboard(double x, double y) { return sin(x) * sin(y); }
double f_cone(double x, double y) { return sqrt(x*x + y*y); }
double f_twisted(double x, double y) { return sin(x*x + y*y); }
double f_cross_waves(double x, double y) { return sin(x) + cos(y); }
double f_spiral(double x, double y) { double r = sqrt(x*x + y*y); return sin(r - atan2(y, x)); }
double f_egg_carton(double x, double y) { return sin(x) + sin(y) + sin(x + y); }
double f_hyperbolic(double x, double y) { return 1.0 / (x*x + y*y + 0.1); }

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
