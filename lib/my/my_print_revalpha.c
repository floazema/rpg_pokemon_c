/*
** EPITECH PROJECT, 2021
** my_print_revalpha
** File description:
** alphabet à l'envers
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (int i = 122; i > 96; i--) {
        my_putchar(i);
    }
    return (0);
}
