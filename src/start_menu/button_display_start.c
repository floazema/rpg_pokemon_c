/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main start menu
*/

#include "rpg.h"

sfVector2f prev_pos = {350, 400};
sfVector2f next_pos = {1300, 400};
sfVector2f start_pos = {770, 600};
sfVector2f save_pos = {650, 370};

void glow_prev_next(start_t *start)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(start->my_rpg);

    if (mouse_pos.x >= prev_pos.x && mouse_pos.x <= prev_pos.x + 240
    && mouse_pos.y >= prev_pos.y && mouse_pos.y <= prev_pos.y + 160) {
        start->buttons->button_rect.left = 0;
        start->buttons->button_rect.top = 84;
        sfSprite_setTextureRect(start->buttons->button_start, start->buttons->button_rect);
        sfSprite_setPosition(start->buttons->button_start, prev_pos);
        sfRenderWindow_drawSprite(start->my_rpg, start->buttons->button_start, NULL);
    }
    if (mouse_pos.x >= next_pos.x && mouse_pos.x <= next_pos.x + 240
    && mouse_pos.y >= next_pos.y && mouse_pos.y <= next_pos.y + 160) {
        start->buttons->button_rect.left = 120;
        start->buttons->button_rect.top = 84;
        sfSprite_setTextureRect(start->buttons->button_start, start->buttons->button_rect);
        sfSprite_setPosition(start->buttons->button_start, next_pos);
        sfRenderWindow_drawSprite(start->my_rpg, start->buttons->button_start, NULL);
    }
    if (mouse_pos.x >= 1720 && mouse_pos.x <= 1920
    && mouse_pos.y >= 0 && mouse_pos.y <= 150
    && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        start->scene = HTP;
    }
}

void glow_start(start_t *start)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(start->my_rpg);

    if (mouse_pos.x >= start_pos.x && mouse_pos.x <= start_pos.x + 360
    && mouse_pos.y >= start_pos.y && mouse_pos.y <= start_pos.y + 340) {
        start->buttons->button_rect.height = 140;
        start->buttons->button_rect.left = 182;
        start->buttons->button_rect.width = 180;
        start->buttons->button_rect.top = 170;
        sfSprite_setTextureRect(start->buttons->button_start, start->buttons->button_rect);
        sfSprite_setPosition(start->buttons->button_start, start_pos);
        sfRenderWindow_drawSprite(start->my_rpg, start->buttons->button_start, NULL);
    }
}

void next_prev_display(start_t *start)
{
    start->buttons->button_rect.height = 80;
    start->buttons->button_rect.left = 0;
    start->buttons->button_rect.width = 120;
    start->buttons->button_rect.top = 0;
    sfSprite_setTextureRect(start->buttons->button_start, start->buttons->button_rect);
    sfSprite_setPosition(start->buttons->button_start, prev_pos);
    sfRenderWindow_drawSprite(start->my_rpg, start->buttons->button_start, NULL);
    start->buttons->button_rect.left = 120;
    sfSprite_setTextureRect(start->buttons->button_start, start->buttons->button_rect);
    sfSprite_setPosition(start->buttons->button_start, next_pos);
    sfRenderWindow_drawSprite(start->my_rpg, start->buttons->button_start, NULL);
}

void start_save_display(start_t *start)
{
    start->buttons->button_rect.height = 140;
    start->buttons->button_rect.left = 0;
    start->buttons->button_rect.width = 180;
    start->buttons->button_rect.top = 170;
    sfSprite_setTextureRect(start->buttons->button_start, start->buttons->button_rect);
    sfSprite_setPosition(start->buttons->button_start, start_pos);
    sfRenderWindow_drawSprite(start->my_rpg, start->buttons->button_start, NULL);
    start->buttons->button_rect.height = 130;
    start->buttons->button_rect.width = 300;
    start->buttons->button_rect.top = 310;
    sfSprite_setTextureRect(start->buttons->button_start, start->buttons->button_rect);
    sfSprite_setPosition(start->buttons->button_start, save_pos);
    sfRenderWindow_drawSprite(start->my_rpg, start->buttons->button_start, NULL);
}

void button_display(start_t *start)
{
    start_save_display(start);
    next_prev_display(start);
    glow_prev_next(start);
    glow_start(start);
}
