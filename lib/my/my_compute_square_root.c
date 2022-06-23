/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** :DDDDD
*/

int my_compute_square_root(int nb)
{
    int root = 1;
    while (root * root != nb) {
        root = root + 1;
        if (root > nb) {
            return (0);
        }
    }
    return root;
}
