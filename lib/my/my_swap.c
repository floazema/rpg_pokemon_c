/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swap
*/

int my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
    return (0);
}
