/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** my_putstr
*/

#include "../../include/miniprintf.h"
#include "../../include/tools.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    if (str == 0)
        return -1;
    return write(1, str, my_strlen(str));
}
