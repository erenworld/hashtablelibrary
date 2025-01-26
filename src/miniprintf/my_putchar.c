/*
** EPITECH PROJECT, 2024
** //
** File description:
** //
*/

#include <unistd.h>
#include "../../include/miniprintf.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}
