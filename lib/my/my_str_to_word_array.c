/*
** EPITECH PROJECT, 2021
** my_str_to_word array!
** File description:
** :3 :^p :-( :) :D :/ ;!
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int nonalpha(char c)
{
    if ((c >= 32 && c <= 126 && c != 64) || c == '\n') {
        return (0);
    } else {
        return (1);
    }
}

int colonlen(char const *str)
{
    int i = 0;
    int k = 1;

    while (str[i] != '\0') {
        if (nonalpha(str[i]) == 1) {
            k++;
            i++;
        } else {
            i++;
        }
    }
    return (k);
}

int linelen(char const *str, int *ptr)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (nonalpha(str[*ptr]) != 1 && str[*ptr] != '\0') {
        *ptr = *ptr + 1;
        i++;
    }
    return (i);
}

char **fill_tab(char const *str, char **tab)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (nonalpha(str[i]) == 1) {
            tab[j][k] = '\0';
            i++;
            j++;
            k = 0;
        } else {
            tab[j][k] = str[i];
            i++;
            k++;
        }
    }
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int ptr = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    tab = malloc(colonlen(str) * sizeof(char *));
    while (str[ptr] != '\0') {
        tab[i] = malloc((linelen(str, &ptr) + 1) * sizeof(char));
        ptr = ptr + 1;
        i++;
    }
    return (fill_tab(str, tab));
}
