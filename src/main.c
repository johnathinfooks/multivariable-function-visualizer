#include "shared.h"

int main()
{
    Table t = calculate_table(f_paraboloid, 0, 1, 0, 1);
    print_table_value(t);
    print_table(t);
}
