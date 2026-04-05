#include "shared.h"

int main()
{
    Table t = calculate_table(f_paraboloid, 0, 2, 0, 2);
    assign_color_intensity(&t);

    print_table_value(t);
    print_table_intensity(t);
}
