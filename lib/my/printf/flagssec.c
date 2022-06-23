/*
** EPITECH PROJECT, 2021
** flags file 2
** File description:
** flags myprintf
*/

#include <stdlib.h>
#include <stdarg.h>

char *my_revstr(char *str);
char *my_putstr(char const *str);
int printxsecptr(char *puthexa, unsigned int nbr);
void my_putchar(char);
int printssec(char *dest, char *octave, int j);

int printsthree(char *dest, char *octave, int j)
{
    if (dest[j] == 127 || dest[j] < 32)
        printssec(dest, octave, j);
    else
        my_putchar(dest[j]);
}

int printxthree(char *puthexa, unsigned int nbr)
{
    unsigned int stock = 0;
    int k = 0;
    while (nbr != 0) {
        stock = nbr % 16;
        if (stock < 10)
            stock += 48;
        else
            stock += 55;
        puthexa[k++] = stock;
        nbr /= 16;
    }
    my_revstr(puthexa);
    my_putstr(puthexa);
}

char *printbsec(char *binary, unsigned int nbr)
{
    int j = 0;

    while (nbr != 0) {
        if (nbr % 2 == 0)
            binary[j] = '0';
        else
            binary[j] = '1';
        nbr /= 2;
        j++;
    }
    return (binary);
}

int printxsec(char *puthexa, unsigned int nbr)
{
    int k = 0;
    unsigned int stock = 0;

    while (nbr != 0) {
        stock = nbr % 16;
        if (stock < 10)
            stock += 48;
        else
            stock += 87;
        puthexa[k++] = stock;
        nbr /= 16;
    }
    my_revstr(puthexa);
    my_putstr(puthexa);
}

int printp(char *str, va_list list_size, int i)
{
    unsigned int nbr;
    char *hexa;

    hexa = malloc(20);
    if (str[i] == 'p') {
        nbr = (va_arg(list_size, unsigned int));
        printxsecptr(hexa, nbr);
    }
}
