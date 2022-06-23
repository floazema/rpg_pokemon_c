/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverse caracter of a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    char stock[i];
    i = 0;
    while (str[i] != '\0') {
        stock[i] = str[i];
        i = i + 1;
    }
    i--;
    int j = 0;
    while (i != -1) {
        str[j] = stock[i];
        i--;
        j++;
    }
    str[j] = '\0';
    return (str);
}
