/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** positif or negative
*/

void my_putchar(char);

int my_isneg(int n)
{
    int nombre = n;
    if (nombre >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
