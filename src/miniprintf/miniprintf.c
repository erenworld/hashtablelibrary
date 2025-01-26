/*
** EPITECH PROJECT, 2024
** My mini_printf
** File description:
** mini_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "../../include/miniprintf.h"

static int verify_format(char specifier, va_list args)
{
    int count = 0;

    if (specifier == 's') {
        count += my_putstr(va_arg(args, char *));
    }
    if (specifier == 'c') {
        count += my_putchar(va_arg(args, int));
    }
    if (specifier == 'i' || specifier == 'd') {
        count += my_put_nbr(va_arg(args, int));
    }
    if (specifier == '%') {
        count += my_putchar('%');
    }
    return count;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            count += verify_format(format[i], args);
        } else {
            count += my_putchar(format[i]);
        }
    }
    va_end(args);
    return count;
}
