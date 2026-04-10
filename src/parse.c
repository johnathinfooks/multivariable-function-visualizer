#include "shared.h"
#include <string.h>

#define SIZE_BUFFER 128

void inside_brackets(char* str)
{
    char* open = strchr(str, '[');
    char* close = strchr(str, ']');
    if (open && close && close > open) {
        int len = close - open - 1;
        memmove(str, open + 1, len);
        str[len] = '\0';
    } else {
        str[0] = '\0';
    }
}

void parse_input(char* eq_str_b, int size_eq_str_b, char* res_str_b, int size_res_str_b)
{
    FILE *fp;
    fp = fopen("INPUT.md", "r");
    fgets(eq_str_b, SIZE_BUFFER, fp);
    fgets(res_str_b, SIZE_BUFFER, fp);
    inside_brackets(eq_str_b);
    inside_brackets(res_str_b);
}
