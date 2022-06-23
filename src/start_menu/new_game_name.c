/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main start menu
*/

#include "rpg.h"

sfVector2f start_posy = {770, 600};

void is_new_game(start_t *start)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(start->my_rpg);

    if ((mouse_pos.x >= start_posy.x && mouse_pos.x <= start_posy.x + 360
    && mouse_pos.y >= start_posy.y && mouse_pos.y <= start_posy.y + 340
    && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && start->scene == NEW_GAME_NAME)
    || (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue && start->scene == NEW_GAME_NAME)) {
        start->scene = NEW_GAME_START;
        sfSound_play(start->buttons->sound);
    }
}
