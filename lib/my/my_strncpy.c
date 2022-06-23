/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** copy n caracter from a string
*/

char *my_strncpy(char *dest , char const *src , int n)
{
    int i = 0;
    int j = 0;
    while (src[j] != '\0') {
        j = j + 1;
    }
    while (i != j && i != n) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
