/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** UwU
*/

#include <stdlib.h>
#include "strcm.h"

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    if (my_strlen2(s1) > my_strlen2(s2))
        return (my_strlen2(s1) - my_strlen2(s2));
    else if (my_strlen2(s1) < my_strlen2(s2))
        return (my_strlen2(s1) - my_strlen2(s2));
    for (i; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i]) {
            j = j - 1;
        }
        else if (s1[i] > s2[i]) {
            j = j + 1;
        }
    }
    return (j);
}

void to_compare(char const *s1, char const *s2, strcm_t *strcm)
{
    int j = 0;

    for (; s2[strcm->i] != '\0' && s1[j] != '\0'; strcm->i++, j++) {
        if (s2[strcm->i] != s1[j])
            break;
    }
    if (s1[j] == '\0')
        strcm->is_good = 1;
}

int cond_str(char const *s1, char const *s2, int j, strcm_t *strcm)
{
    if (s2[strcm->i] == s1[j])
        to_compare(s1, s2, strcm);
}

int my_strcmpn(char const *s1, char const *s2, int i)
{
    strcm_t *strcm = malloc(sizeof(strcm_t));
    int j = 0;

    strcm->i = i;
    strcm->is_good = 0;
    for (; s1[j] != '\0' && s2[strcm->i] != '\0'; strcm->i++) {
        cond_str(s1, s2, j, strcm);
        if (strcm->is_good == 1)
            break;
    }
    if (strcm->is_good == 1)
        return strcm->i;
    else
        return -1;
}
