/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-florian.azema
** File description:
** sound
*/

#include "rpg.h"

int gen_sound(buttons_t *button)
{
    button->soundbuffer = sfSoundBuffer_createFromFile("assets/click.ogg");
    if (button->soundbuffer == NULL) {
        my_printf("bonjour monsieur l'aer\n");
        return 84;
    }
    button->sound = sfSound_create();
    sfSound_setBuffer(button->sound, button->soundbuffer);
    return 0;
}
