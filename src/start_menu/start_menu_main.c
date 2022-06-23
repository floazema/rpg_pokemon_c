/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main start menu
*/

#include "rpg.h"

static const int window_height = 1080;
static const int window_width = 1920;
static const int bits_per_pixel = 32;
sfVector2f cloud_pos_2 = {1920, 0};
sfVector2f scale_button = {2, 2};

void bird_pos_set(start_t *start)
{
    start->birds->bird_pos[0].x = 1920;
    start->birds->bird_pos[1].x = 300;
    start->birds->bird_pos[2].x = 500;
    start->birds->bird_pos[3].x = 1600;
    start->birds->bird_pos[4].x = 1400;
    start->birds->bird_pos[5].x = 1200;
    start->birds->bird_pos[0].y = 700;
    start->birds->bird_pos[1].y = 340;
    start->birds->bird_pos[2].y = 550;
    start->birds->bird_pos[3].y = 120;
    start->birds->bird_pos[4].y = 420;
    start->birds->bird_pos[5].y = 830;
}

sfIntRect bird_rect_create(sfIntRect rect)
{
    rect.height = 50;
    rect.left = 0;
    rect.width = 47;
    rect.top = 0;
    return (rect);
}

int create_scene_start(start_t *start)
{
    create_sprite("assets/start_menu_background.jpg", &start->menu_background,
    &start->texture_menu_background, NULL);
    create_sprite("assets/cloud_start.png", &start->clouds->cloud_start,
    &start->clouds->texture_cloud_start, NULL);
    create_sprite("assets/cloud_start.png", &start->clouds->cloud_start_2,
    &start->clouds->texture_cloud_start, &cloud_pos_2);
    create_sprite("assets/birds.png", &start->birds->birds_start,
    &start->birds->texture_birds_start, NULL);
    create_sprite("assets/button_start.png", &start->buttons->button_start,
    &start->buttons->texture_button_start, NULL);
    bird_pos_set(start);
    sfSprite_setScale(start->buttons->button_start, scale_button);
    if (gen_sound(start->buttons) == 84)
        return 84;
    start->clouds->cloud_c = sfClock_create();
    start->birds->bird_c = sfClock_create();
    start->clouds->cloud_s = 0;
    start->birds->bird_s = 0;
    start->birds->bird_rect = bird_rect_create(start->birds->bird_rect);
}

int init_start(start_t *start, game_t *game)
{
    sfVideoMode mode = {window_width, window_height, bits_per_pixel};

    start->birds = malloc(sizeof(birds_t));
    start->clouds = malloc(sizeof(clouds_t));
    start->buttons = malloc(sizeof(buttons_t));
    start->saves = malloc(sizeof(saves_t));
    init_save(start);
    game->count_rect = 0;
    game->stats = 0;
    game->status = 0;
    create_sprite("assets/help.jpg", &start->help, &start->texture_help, NULL);
    game->map = HOUSE_START;
    start->my_rpg = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    start->scene = START_MENU;
    start->saves->load_save = 0;
    if (create_scene_start(start) == 84)
        return 84;
}

void handle_start_menu(start_t *start)
{
    if (start->scene == START_MENU) {
        sfRenderWindow_drawSprite(start->my_rpg, start->menu_background, NULL);
        do_parralax_cloud_bird(start);
        button_display(start);
        sfRenderWindow_drawText(start->my_rpg, start->saves->saveText, NULL);
    }
    if (start->scene == HTP)
        sfRenderWindow_drawSprite(start->my_rpg, start->help, NULL);
    if (start->scene == NEW_GAME_START) {
        sfRenderWindow_drawSprite(start->my_rpg, start->menu_background, NULL);
        do_parralax_cloud_bird(start);
    }
    if (start->scene == NEW_GAME_NAME) {
        sfRenderWindow_drawSprite(start->my_rpg, start->menu_background, NULL);
        do_parralax_cloud_bird(start);
        start_save_display(start);
        glow_start(start);
        sfRenderWindow_drawText(start->my_rpg, start->saves->saveText, NULL);
    }
}
