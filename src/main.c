#include "shared.h"

int main()
{
    Table t = calculate_table(f_paraboloid, 0, 10, 0, 10);
    assign_color_intensity(&t);

    print_table_intensity(t);
    print_table_color(t);
}
