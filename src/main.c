#include "shared.h"

int main()
{
    Table t = calculate_table(f_sine_wave, -5, 5, -5, 5);
    assign_color_intensity(&t);

    print_table_intensity(t);
    print_table_color(t);
}
