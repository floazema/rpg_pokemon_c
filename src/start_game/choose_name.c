/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main body rpg, game loop ...
*/

#include "rpg.h"

sfVector2f classic_scale = {1, 1};
sfVector2f low_scale = {0.35, 0.35};
sfVector2f text_pos_set = {0, 680};
sfVector2f name_box = {650, 400};

void choose_name(start_t *start, game_t *game)
{
    sfSprite_setPosition(game->text_box, name_box);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue && game->status == NAME
    && game->display[game->text_char] == '@') {
        game->status = START_AVENTURE;
        game->count = 0;
        memset(&game->stock, 0, sizeof(game->stock));
        game->text_char++;
    }
    sfSprite_setScale(game->text_box, low_scale);
    sfRenderWindow_drawSprite(start->my_rpg, game->text_box, NULL);
    sfSprite_setScale(game->text_box, classic_scale);
    sfSprite_setPosition(game->text_box, text_pos_set);
    sfText_setString(game->name_text, game->name);
    sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
}
