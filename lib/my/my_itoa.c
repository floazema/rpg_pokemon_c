/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** positif or negative
*/

#include "my.h"
#include <stdlib.h>

char *my_itoa(int num)
{
    int i = 0, stock = 0, j = 0;
    char *str;

    str = malloc(100);
    if (num < 0)
        j = 1, num *= -1;
    if (num == 0) {
        str[i++] = '0', str[i] = '\0';
        return str;
    }
    while (num != 0) {
        stock = num % 10;
        num /= 10, str[i] = stock + 48, i++;
    }
    if (j == 1)
        str[i] = '-', i++;
    str[i] = '\0';
    my_revstr(str);
    return str;
}
