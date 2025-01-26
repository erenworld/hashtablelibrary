/*
** EPITECH PROJECT, 2024
** MY_ATOI
** File description:
** DESCRIPTION
*/

#include "../../include/tools.h"

static int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

static int get_sign(const char **str)
{
    int sign = 1;

    while (**str == '+' || **str == '-') {
        if (**str == '-')
            sign *= -1;
        (*str)++;
    }
    return sign;
}

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 0;

    if (str == 0)
        return 0;
    sign = get_sign(&str);
    while (is_digit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
