/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** myprintf
*/

#include <stdarg.h>
#include <stdlib.h>

int printprcnt(char *str, va_list list_size, int i);
int printall(char *str, va_list list_size, int i);
int printu(char *str, va_list list_size, int i);
int printX(char *str, va_list list_size, int i);
int printx(char *str, va_list list_size, int i);
int printo(char *str, va_list list_size, int i);
int printb(char *str, va_list list_size, int i);
int my_put_nbr(int);
int my_put_unnbr(unsigned int);
char *my_strcpy(char *dest, char const *src);
int printbsec(char *binary, unsigned int nbr);
char *my_revstr(char *str);
int my_put_unnbr(unsigned int nb);
char *my_putstr(char const *str);
void my_putchar(char);
int printxthree(char *puthexa, unsigned int nbr);
int printxsec(char *puthexa, unsigned int nbr);
int my_strlen(char const *str);
int printsthree(char *dest, char *octave, int j);
int printxsec(char *puthexa, unsigned int nbr);
int printp(char *str, va_list list_size, int i);
int printxsecond(char *str, va_list list_size, int i);

int my_printf(char *str, ...)
{
    va_list list_size;
    int i = 0;

    va_start(list_size, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            printall(str, list_size, i);
            i++;
        }
        my_putchar(str[i]);
        i++;
    }
    va_end(list_size);
}

int printprcnt(char *str, va_list list_size, int i)
{
    if (str[i] == '%')
        my_putchar('%');
}

int printsnum(char *str, va_list list_size, int i)
{
    char *dest;
    char *octave;
    int j = 0, k = 0, count = 0;

    octave = malloc(5);
    dest = malloc(my_strlen(str) * 100);
    if (str[i] == 'S') {
        my_strcpy(dest, va_arg(list_size, char *));
        while (dest[j] != '\0') {
            octave[0] = 48;
            octave[1] = 48;
            octave[2] = 48;
            octave[3] = 92;
            printsthree(dest, octave, j);
            j++;
        }
    }
}

int printall(char *str, va_list list_size, int i)
{
    if (str[i] == 's')
        my_putstr(va_arg(list_size, char *));
    if (str[i] == 'c')
        my_putchar(va_arg(list_size, int));
    if (str[i] == 'i' || str[i] == 'd')
        my_put_nbr(va_arg(list_size, int));
    printsnum(str, list_size, i);
    printb(str, list_size, i);
    printo(str, list_size, i);
    printu(str, list_size, i);
    printxsecond(str, list_size, i);
    printx(str, list_size, i);
    printprcnt(str, list_size, i);
    printp(str, list_size, i);
}

int printssec(char *dest, char *octave, int j)
{
    int count = 0, k = 0;
    k = dest[j];
    while (k != 0) {
        while (octave[0] != '8' && k != 0) {
            octave[0] += 1;
            count++;
            k--;
        }
        if (octave[0] == 8 + '0') {
            octave[0] = '0' - 2;
            octave[1] += 1;
        }
        if (octave[1] == 8 + '0') {
            octave[1] = '0' - 2;
            octave[2] += 1;
        }
        count = 0;
    }
    my_revstr(octave);
    my_putstr(octave);
}
