/*
** EPITECH PROJECT, 2024
** MY_STRCMP
** File description:
** DESCRIPTION
*/

#include "../../include/tools.h"
#include <stdlib.h>

char *my_strdup(const char *src)
{
    int len = 0;
    char *dest = 0;

    if (src == 0)
        return 0;
    len = my_strlen(src) + 1;
    dest = malloc(sizeof(char) * len);
    if (dest == 0)
        return 0;
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    return dest;
}
