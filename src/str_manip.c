/*
** EPITECH PROJECT, 2022
** str_manip.c
** File description:
** str manipulaton
*/

#include "rpg.h"

int fill_strtab(char **array)
{
    char *buffer;
    FILE *fd;
    char *filename = "assets/dialogue.txt";

    buffer = malloc(sizeof(char) * 1000);
    fd = fopen(filename, "r");
    if (fd == -1)
        return 1;
    fread (buffer, 1, 1000, fd);
    array = my_str_to_word_array(buffer);
    return 0;
}
