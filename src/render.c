#include "shared.h"

int assign_color_intensity(Table *t)
{
    t->min_val = t->slot[0].value;
    t->max_val = t->slot[0].value;
    for (int i = 1; i < TABLE_SIZE; i++) {
        if (t->slot[i].value > t->max_val) t->max_val = t->slot[i].value;
        if (t->slot[i].value < t->min_val) t->min_val = t->slot[i].value;
    }

    double step = (t->max_val - t->min_val) / 8.0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        double v = t->slot[i].value;
        if (v < t->min_val + step * 1) {
            t->slot[i].color = light_green;
        } else if (v < t->min_val + step * 2) {
            t->slot[i].color = green;
        } else if (v < t->min_val + step * 3) {
            t->slot[i].color = light_yellow;
        } else if (v < t->min_val + step * 4) {
            t->slot[i].color = yellow;
        } else if (v < t->min_val + step * 5) {
            t->slot[i].color = light_orange;
        } else if (v < t->min_val + step * 6) {
            t->slot[i].color = orange;
        } else if (v < t->min_val + step * 7) {
            t->slot[i].color = light_red;
        } else {
            t->slot[i].color = red;
        }
    }

    return 1;
}

int print_table_intensity(Table table)
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
            printf("\n\n\t");
        }
        printf("%05.2f  ", table.slot[i].value);
    }
    printf("\n\n");

    return 1;
}
