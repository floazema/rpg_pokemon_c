/*
** EPITECH PROJECT, 2021
** aefskofeslc
** File description:
** asvjsefs
*/

int my_atoi(char *av)
{
    int i = 0;
    int chartonumber = 0;
    int isneg = 0;

    while (av[i] != '\0') {
        if (av[i] == '-') {
            isneg = -1;
            i++;
        }
        chartonumber *= 10;
        chartonumber += av[i] - 48;
        i++;
    }
    if (isneg == -1)
        chartonumber *= -1;
    return chartonumber;
}
