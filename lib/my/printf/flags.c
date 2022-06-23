/*
** EPITECH PROJECT, 2021
** mrflags
** File description:
** flags
*/

#include <stdarg.h>
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);
int printbsec(char *binary, unsigned int nbr);
char *my_revstr(char *str);
int my_put_unnbr(unsigned int nb);
char *my_putstr(char const *str);
int printxthree(char *puthexa, unsigned int nbr);
int printxsec(char *puthexa, unsigned int nbr);

int printb(char *str, va_list list_size, int i)
{
    char *binary;
    int j = 0;
    int k = 0;
    unsigned int nbr = 0;
    binary = malloc(10000);
    if (str[i] == 'b') {
        nbr = va_arg(list_size, unsigned int);
    }
    my_revstr(binary);
    my_putstr(binary);
}

int printo(char *str, va_list list_size, int i)
{
    unsigned int octal;
    int mult = 1;
    int k = 0;
    unsigned int nbr = 0;
    unsigned int stock = 0;

    if (str[i] == 'o') {
        nbr = va_arg(list_size, unsigned int);
        while (nbr != 0) {
            stock = nbr % 8;
            nbr /= 8;
            octal += stock * mult;
            mult *= 10;
        }
        my_put_unnbr(octal);
    }
}

int printu(char *str, va_list list_size, int i)
{
    unsigned int nbr = 0;

    if (str[i] == 'u') {
        nbr = va_arg(list_size, unsigned int);
        my_put_unnbr(nbr);
    }
}

int printxsecond(char *str, va_list list_size, int i)
{
    char *puthexa;
    int k = 0;
    unsigned int nbr = 0;

    puthexa = malloc(10000);
    if (str[i] == 'X') {
        nbr = va_arg(list_size, unsigned int);
        printxthree(puthexa, nbr);
    }
}

int printx(char *str, va_list list_size, int i)
{
    char *puthexa;
    int k = 0;
    unsigned int nbr = 0;
    unsigned int stock = 0;
    puthexa = malloc(10000);
    if (str[i] == 'x') {
        nbr = va_arg(list_size, unsigned int);
        printxsec(puthexa, nbr);
    }
}
