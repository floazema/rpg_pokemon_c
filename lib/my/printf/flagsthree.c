/*
** EPITECH PROJECT, 2021
** flagsthree
** File description:
** flagsthree
*/

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

int printxsecptr(char *puthexa, unsigned int nbr)
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
