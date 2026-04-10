#include "shared.h"

void display(const char *name, Function f, double xmin, double xmax, double ymin, double ymax)
{
    printf("\n%s\n", name);
    Table t = calculate_table(f, xmin, xmax, ymin, ymax);
    assign_color_intensity(&t);
    print_table_color(t);
}

int main()
{
    display("sine wave", f_sine_wave, -M_PI, M_PI, -M_PI, M_PI);
    display("paraboloid", f_paraboloid, -4, 4, -4, 4);
    display("saddle", f_saddle, -4, 4, -4, 4);
    display("ripple", f_ripple, -12, 12, -12, 12);
    display("peaks", f_peaks, -3, 3, -3, 3);
    display("checkerboard", f_checkerboard, -3*M_PI, 3*M_PI, -3*M_PI, 3*M_PI);
    display("cone", f_cone, -6, 6, -6, 6);
    display("twisted", f_twisted, -4, 4, -4, 4);
    display("cross waves", f_cross_waves, -2*M_PI, 2*M_PI, -2*M_PI, 2*M_PI);
    display("spiral", f_spiral, -6, 6, -6, 6);
    display("egg carton", f_egg_carton, -2*M_PI, 2*M_PI, -2*M_PI, 2*M_PI);
    display("hyperbolic", f_hyperbolic, -4, 4, -4, 4);
}
