#include "shared.h"

int assign_color_intensity(Table *t)
{
    t->min_val = t->slot[0].value;
    t->max_val = t->slot[0].value;
    for (int i = 1; i < TABLE_SIZE; i++) {
        if (t->slot[i].value > t->max_val) t->max_val = t->slot[i].value;
        if (t->slot[i].value < t->min_val) t->min_val = t->slot[i].value;
    }

    double step = (t->max_val - t->min_val) / 16.0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        double v = t->slot[i].value;

        if (v < t->min_val + step * 1) {
            t->slot[i].color = pale_blue;
        } else if (v < t->min_val + step * 2) {
            t->slot[i].color = light_blue;
        } else if (v < t->min_val + step * 3) {
            t->slot[i].color = blue;
        } else if (v < t->min_val + step * 4) {
            t->slot[i].color = bright_blue;
        } else if (v < t->min_val + step * 5) {
            t->slot[i].color = bright_cyan;
        } else if (v < t->min_val + step * 6) {
            t->slot[i].color = light_cyan;
        } else if (v < t->min_val + step * 7) {
            t->slot[i].color = cyan;
        } else if (v < t->min_val + step * 8) {
            t->slot[i].color = teal;
        } else if (v < t->min_val + step * 9) {
            t->slot[i].color = light_green;
        } else if (v < t->min_val + step * 10) {
            t->slot[i].color = green;
        } else if (v < t->min_val + step * 11) {
            t->slot[i].color = yellow_green;
        } else if (v < t->min_val + step * 12) {
            t->slot[i].color = light_yellow;
        } else if (v < t->min_val + step * 13) {
            t->slot[i].color = yellow;
        } else if (v < t->min_val + step * 14) {
            t->slot[i].color = orange;
        } else if (v < t->min_val + step * 15) {
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
            printf("\n\n\t");
        }
        printf("%.2d  ", table.slot[i].color);
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

int print_table_color(Table t)
{
    int color_codes[] = { 153, 117, 75, 39, 51, 87, 44, 37, 83, 82, 118, 190, 226, 214, 202, 196 };

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (i % RESOLUTION == 0) {
            printf("\n\t");
        }
        printf("\033[38;5;%dm██\033[0m", color_codes[t.slot[i].color]);
    }
    printf("\n\n");

    return 1;

}
