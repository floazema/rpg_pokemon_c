/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main start menu
*/

#include "rpg.h"

void a_to_z(sfKeyCode code, char *str, char *tab, int i)
{
    if (code == (i))
        str[my_strlen(str)] = tab[i];
}


void manage_key (sfKeyCode code, char *str)
{
    char tab[] = "abcdefghijklmnopqrstuvwxyz ";

    if (my_strlen(str) <= 10)
        for (int i = 0; i != 25; i++)
            a_to_z(code, str, tab, i);
    if (code == (sfKeyBack))
        str[my_strlen(str) - 1] = '\0';
}
