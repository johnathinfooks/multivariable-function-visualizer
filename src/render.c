#include "shared.h"

int print_table(Table table)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (i % RESOLUTION == 0) {
            printf("\n\t");
        }
        printf("%d ", table.slot[i].color);
    }
    printf("\n\n");

    return 1;
}

int print_table_value(Table table)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (i % RESOLUTION == 0) {
            printf("\n\t");
        }
        printf("%f ", table.slot[i].value);
    }
    printf("\n\n");

    return 1;
}
