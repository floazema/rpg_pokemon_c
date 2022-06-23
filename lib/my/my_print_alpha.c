/*
** EPITECH PROJECT, 2021
** my_print_alpha
** File description:
** alphabet
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (int i = 97; i < 123; i++) {
        my_putchar(i);
    }
    return (0);
}
