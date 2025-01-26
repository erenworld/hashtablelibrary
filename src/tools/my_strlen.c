/*
** EPITECH PROJECT, 2024
** MY_STRLEN
** File description:
** DESCRIPTION
*/

#include "../../include/tools.h"

int my_strlen(char const *str)
{
    int nb = 0;

    for (; str[nb] != '\0'; nb++);
    return nb;
}
