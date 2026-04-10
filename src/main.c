#include "shared.h"

int main()
{
    // Table t = calculate_table(f_paraboloid, 0, 10, 0, 10);
    // assign_color_intensity(&t);
    //
    // print_table_intensity(t);
    // print_table_color(t);

    const int SIZE = 128;
    char eq_str[SIZE];
    char res_str[SIZE];
    parse_input(eq_str, SIZE, res_str, SIZE);
    printf("EQ: %s\tRES: %s\n", eq_str, res_str);
}
