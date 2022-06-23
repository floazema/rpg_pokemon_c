/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** UwU
*/

#include <stdlib.h>
#include "strcm.h"
#include "my.h"

void to_compare2(char const *s1, char const *s2, strcm_t *strcm, int j)
{

    for (; j != -1, strcm->i != -1 ; strcm->i--, j--) {
        if (s2[strcm->i] != s1[j])
            break;
        if (j == 0)
            break;
    }
    if (j == 0) {
        strcm->is_good = 1;
    }
}

int cond_str2(char const *s1, char const *s2, int j, strcm_t *strcm)
{
    if (s2[strcm->i] == s1[j])
        to_compare2(s1, s2, strcm, j);
}

int my_strcmpd(char const *s1, char const *s2, int i, int k)
{
    strcm_t *strcm = malloc(sizeof(strcm_t));
    int j = my_strlen(s1) - 1;
    int y = 0;

    strcm->i = i;
    strcm->is_good = 0;
    for (; 1 ; strcm->i--, y++) {
        cond_str2(s1, s2, j, strcm);
        if (strcm->is_good == 1) {
            break;
        }
        if (strcm->i == 0)
            strcm->i = k;
    }
    if (strcm->is_good == 1)
        return strcm->i;
    else
        return -1;
}
