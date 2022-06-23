/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    while (src[i] != 0) {
        i++;
    }
    char *dest = NULL;
    dest = malloc(i);
    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
