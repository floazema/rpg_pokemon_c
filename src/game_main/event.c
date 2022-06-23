/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event game
*/

#include "rpg.h"

void manage_event4(start_t *start, game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && start->scene == WORLD) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue
        || sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue || sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        is_fight(start, game);
    }
    if (event.type == sfEvtKeyPressed && start->scene == NEW_GAME_NAME) {
        manage_key(event.key.code, start->saves->current_save);
        sfText_setString(start->saves->saveText, start->saves->current_save);
    }
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyA) ==
     sfTrue && start->scene == BOSS) {
        start->scene = FIGHT;
        game->cbt = SELECT;
        game->cbt = 0;
        game->enemy_dmg = 0;
        game->ally_dmg = 0;
        set_pokemon_random(game, start);
    }
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyA) ==
     sfTrue && start->scene == QUETE) {
        start->scene = WORLD;
    }
    if (event.type == sfEvtKeyPressed && game->alealv >= 50 &&
    sfKeyboard_isKeyPressed(sfKeyA)== sfTrue && game->map == CITY
    && start->scene == WORLD) {
        start->scene = BOSS;
    }
    if (event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyA)== sfTrue && game->map == CITY
    && start->scene == WORLD && game->stats == 6) {
        game->stats = 7;
        start->scene = QUETE;
    }
}

void manage_event3(start_t *start, game_t *game, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && game->cbt == SWAP && game->k != game->j)
        game->k++;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && game->cbt == SWAP && game->k != 0)
        game->k--;
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue && game->cbt == SWAP)
        game->cbt = SELECT;
    if ((event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue) && start->scene == WORLD)
        start->scene = MENU;
    if (event.type == sfEvtKeyPressed && game->status == NAME)
        manage_key(event.key.code, game->name);
    if (event.type == sfEvtKeyPressed && game->status == START_AVENTURE) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && game->count_rect != 0)
            game->count_rect -= 3;
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && game->count_rect != 6)
            game->count_rect += 3;
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(start->my_rpg);
    manage_event4(start, game, event);
}

void manage_event2(start_t *start, game_t *game, sfEvent event)
{
    if ((event.type == sfEvtKeyPressed && start->scene == FIGHT && game->cbt != SWAP)) {
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && game->pos_rect.x != 880)
            game->pos_rect.x += 400;
        if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && game->pos_rect.y != 980)
            game->pos_rect.y += 70;
        if (sfKeyboard_isKeyPressed(sfKeyA) && game->pos_rect.x == 880 && game->pos_rect.y == 980
        && game->alealv <= 50 && game->j <= 10) {
            game->cbt = CAPTURE;
        }
        if (sfKeyboard_isKeyPressed(sfKeyA) && game->pos_rect.x == 880 && game->pos_rect.y == 910)
            game->cbt = SWAP;
        if (sfKeyboard_isKeyPressed(sfKeyA) && game->pos_rect.x == 480 && game->pos_rect.y == 910) {
            game->ally_dmg += (10 + (game->pokemon[game->k].level * 2));
            game->pokemon[game->k].hp += (10 + (game->alealv * 2));
        }
    }
    manage_event3(start, game, event);
}

void manage_event(start_t *start, game_t *game)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(start->my_rpg);
    memset(&event, 0, sizeof(sfEvent));

    while (sfRenderWindow_pollEvent(start->my_rpg, &event)) {
        if (mouse_pos.x >= 0 && mouse_pos.x <= 150
        && mouse_pos.y >= 0 && mouse_pos.y <= 150
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && start->scene == START_MENU && event.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(start->my_rpg);
        }
        if (start->scene == HTP && mouse_pos.x >= 0 && mouse_pos.x <= 450
        && mouse_pos.y >= 0 && mouse_pos.y <= 200
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && event.type == sfEvtMouseButtonPressed) {
            start->scene = START_MENU;
        }
        if ((event.type == sfEvtMouseButtonPressed || event.type == sfEvtKeyPressed)
        && start->scene == START_MENU)
            is_button_pressed(start);
        if ((event.type == sfEvtKeyPressed || event.type == sfEvtMouseButtonPressed)
        && start->scene == NEW_GAME_NAME && my_strcmp("Enter Name", start->saves->current_save) != 0) {
            is_new_game(start);
        }
        if ((event.type == sfEvtKeyPressed && start->scene == FIGHT)) {
            if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && game->pos_rect.x != 480)
                game->pos_rect.x -= 400;
            if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && game->pos_rect.y != 910)
                game->pos_rect.y -= 70;
        }
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            start->scene = MENU;
        manage_event2(start, game, event);
    }
}
