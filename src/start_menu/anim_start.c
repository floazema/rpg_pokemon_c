/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main start menu
*/

#include "rpg.h"

void reset_parralax_cloud(start_t *start, sfVector2f cloud_pos_1,
sfVector2f cloud_pos_2)
{
    if (cloud_pos_1.x <= -1920) {
        cloud_pos_1.x = 1920,
        sfSprite_setPosition(start->clouds->cloud_start, cloud_pos_1);
    }
    if (cloud_pos_2.x <= -1920) {
        cloud_pos_2.x = 1920;
        sfSprite_setPosition(start->clouds->cloud_start_2, cloud_pos_2);
    }
}

void cloud_moove(start_t *start, sfVector2f cloud_pos_1,
sfVector2f cloud_pos_2)
{
    cloud_pos_1.x -= 0.5;
    cloud_pos_2.x -= 0.5;
    sfSprite_setPosition(start->clouds->cloud_start, cloud_pos_1);
    sfSprite_setPosition(start->clouds->cloud_start_2, cloud_pos_2);
}

void bird_moove(start_t *start)
{
    for (int i = 0; i != 6; i++) {
        start->birds->bird_pos[i].x -= 1;
    }
}

void bird_clock(start_t *start)
{
    start->birds->bird_t = sfClock_getElapsedTime(start->birds->bird_c);
    start->birds->bird_s = start->birds->bird_t.microseconds / 1000000.0;
    if (start->birds->bird_s >= 0.3) {
        if (start->birds->bird_rect.left == 0)
            start->birds->bird_rect.left = 47;
        else
            start->birds->bird_rect.left = 0;
        sfClock_restart(start->birds->bird_c);
    }
    for (int i = 0; i != 6; i++) {
        if (start->birds->bird_pos[i].x <= -50)
            start->birds->bird_pos[i].x = 1920;
        sfSprite_setPosition(start->birds->birds_start, start->birds->bird_pos[i]);
        sfSprite_setTextureRect(start->birds->birds_start, start->birds->bird_rect);
        sfRenderWindow_drawSprite(start->my_rpg, start->birds->birds_start, NULL);
        start->birds->bird_rect.top += 50;
    }
    start->birds->bird_rect.top = 0;
}

void do_parralax_cloud_bird(start_t *start)
{
    sfVector2f cloud_pos_1 = sfSprite_getPosition(start->clouds->cloud_start);
    sfVector2f cloud_pos_2 = sfSprite_getPosition(start->clouds->cloud_start_2);

    reset_parralax_cloud(start, cloud_pos_1, cloud_pos_2);
    start->clouds->cloud_t = sfClock_getElapsedTime(start->clouds->cloud_c);
    start->clouds->cloud_s = start->clouds->cloud_t.microseconds / 1000000.0;
    if (start->clouds->cloud_s >= 0.01) {
        cloud_moove(start, cloud_pos_1, cloud_pos_2);
        bird_moove(start);
        sfClock_restart(start->clouds->cloud_c);
    }
    sfRenderWindow_drawSprite(start->my_rpg, start->clouds->cloud_start, NULL);
    sfRenderWindow_drawSprite(start->my_rpg, start->clouds->cloud_start_2, NULL);
    bird_clock(start);
}
