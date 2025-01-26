/*
** EPITECH PROJECT, 2023
** miniprintf header
** File description:
** DESCRIPTION
*/

#ifndef MINIPRINTF_H
    #define MINIPRINTF_H
    #include <stdarg.h>

int my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int mini_printf(const char *format, ...);

#endif /* MINIPRINTF_H */
