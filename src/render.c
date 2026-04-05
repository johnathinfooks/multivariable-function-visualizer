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
