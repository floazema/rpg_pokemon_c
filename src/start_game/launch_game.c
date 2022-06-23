/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main body rpg, game loop ...
*/

#include "rpg.h"

static const sfVector2f text_pos = {160, 810};
static const sfVector2f scale_text_s = {1.3, 1.3};
static const sfVector2f boy_pos = {550, 150};
static const sfVector2f girl_pos = {1100, 160};
static const sfVector2f perso_scale = {2, 2};
static const sfVector2f chen_scale = {1.8, 1.8};
static const sfColor opacity = {255, 255, 255, 125};
static const sfColor opacity_base = {255, 255, 255, 255};
static const sfVector2f text_pos_set_str = {820, 455};
static const char start_text[] = "Bonjour !\nc'est un Plaisir de te rencontrer, mon nom est jhon\n\
Mais tout le monde m'appelle professeur #Avant de commencer, c'est le debut d'une aventure\n\
Si tu as besoin de conseils, je suis tout a fait apte\na t'en donner !#Assez parlez de moi, parlons\
un peu de toi :\nEs tu un garcon ? \n ou bien une fille ?# Daccord je vois vu ta tete j'aurais cru l'inverse\n\
bon dit moi c'est quoi ton petit nom ?\n appuie sur entree pour valider@ Tu as pour quete de vaincre maitre nico\n pour ca il te faut un esclave\
\nBref quel esclave veux tu, appuie sur entree@ :D:D";

void text_display2(game_t *game, start_t *start)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue && game->status == START_AVENTURE
    && game->display[game->text_char] == '@') {
        start->scene = WORLD;
    }
    if (game->display[game->text_char] == '#' && (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue))
    {
        game->count = 0;
        memset(&game->stock, 0, sizeof(game->stock));
        game->text_char++;
    }
    if (game->text_char == 226)
        game->status = GENDER;
    if (game->text_char == 310)
        game->status = NAME;
    sfText_setColor(game->prestext, sfBlack);
    sfRenderWindow_drawText(start->my_rpg, game->prestext, NULL);
}

void text_display(game_t *game, start_t *start)
{
    game->text_t = sfClock_getElapsedTime(game->text_c);
    game->text_s = game->text_t.microseconds / 1000000.0;
    if (game->text_s >= 0.02) {
        if (game->display[game->text_char] != '#' &&
        game->display[game->text_char] != '@') {
            game->stock[game->count] = game->display[game->text_char];
            game->text_char++;
            game->count++;
            sfClock_restart(game->text_c);
            sfText_setString(game->prestext, game->stock);
        }
    }
    text_display2(game, start);
}

void init_game_start(game_t *game)
{
    sfVector2f pos_text_box = {0, 680};
    sfVector2f shen_pos = {800, 50};

    game->sexe_perso = 0;
    game->status = PROF;
    game->text_c = sfClock_create();
    game->prestext = sfText_create();
    create_sprite("assets/text_box.png", &game->text_box, &game->texture_text_box,
    &pos_text_box);
    create_sprite("assets/perso.png", &game->perso, &game->texture_perso, NULL);
    game->pokefont = sfFont_createFromFile("assets/pokemon.ttf");
    create_sprite("assets/professeur.png", &game->chen, &game->texture_chen, &shen_pos);
    sfText_setFont(game->prestext, game->pokefont);
    create_sprite("assets/pokemon.png", &game->sal, &game->texture_sal, NULL);
    sfSprite_setScale(game->chen, chen_scale);
    sfText_setPosition(game->prestext, text_pos);
}

void init_game(game_t *game)
{
    init_game_start(game);
    game->persorect.left = 250;
    game->text_char = 0;
    game->perso_c = sfClock_create();
    game->count = 0;
    sfText_setScale(game->prestext, scale_text_s);
    my_strcpy(game->display, start_text);
    game->name_text = sfText_create();
    sfText_setFont(game->name_text, game->pokefont);
    sfText_setPosition(game->name_text, text_pos_set_str);
    sfText_setColor(game->name_text, sfBlack);
    sfSprite_setScale(game->perso, perso_scale);
}

void girl_set(game_t *game, start_t *start)
{
    sfSprite_setPosition(game->perso, girl_pos);
    game->persorect.top = 510;
    sfSprite_setTextureRect(game->perso, game->persorect);
    sfRenderWindow_drawSprite(start->my_rpg, game->perso, NULL);
}

void display_boy(game_t *game)
{
    if (game->perso_s >= 0.2) {
        if (game->persorect.left >= 600)
            game->persorect.left = 110;
        game->persorect.left += 140;
        sfClock_restart(game->perso_c);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        game->sexe_perso = 0;
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        game->sexe_perso = 510;
    if (game->sexe_perso == 510)
        sfSprite_setColor(game->perso, opacity);
    else
        sfSprite_setColor(game->perso, opacity_base);
}

void display_girl_boy(game_t *game, start_t *start)
{
    display_boy(game);
    game->perso_t = sfClock_getElapsedTime(game->perso_c);
    game->perso_s = game->perso_t.microseconds / 1000000.0;
    game->persorect.height = 260;
    game->persorect.width = 140;
    game->persorect.top = 0;
    sfSprite_setPosition(game->perso, boy_pos);
    sfSprite_setTextureRect(game->perso, game->persorect);
    sfRenderWindow_drawSprite(start->my_rpg, game->perso, NULL);
    if (game->sexe_perso == 0)
        sfSprite_setColor(game->perso, opacity);
    else
        sfSprite_setColor(game->perso, opacity_base);
    girl_set(game, start);
}

void choose_salamwesh(start_t *start, game_t *game)
{
    sfVector2f pos1 = {200, 200};
    sfSprite_setTextureRect(game->sal, game->pokerec);
    sfSprite_setPosition(game->sal, pos1);
    if (game->count_rect == 0)
        sfSprite_setColor(game->sal, opacity_base);
    else
        sfSprite_setColor(game->sal, opacity);
    sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
    game->pokerec.left = 500;
    pos1.x += 100;
    pos1.y -= 100;
    sfText_setString(game->name_text, "Salamwesh");
    sfText_setPosition(game->name_text, pos1);
    sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
}

void choose_carapuceau(start_t *start, game_t *game)
{
    sfVector2f pos2 = {750, 200};
    sfSprite_setTextureRect(game->sal, game->pokerec);
    sfSprite_setPosition(game->sal, pos2);
    if (game->count_rect == 3)
        sfSprite_setColor(game->sal, opacity_base);
    else
        sfSprite_setColor(game->sal, opacity);
    sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
    game->pokerec.left = 1000;
    pos2.x += 20;
    pos2.y -= 100;
    sfText_setString(game->name_text, "Carapuceau");
    sfText_setPosition(game->name_text, pos2);
    sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
}

void choose_bulbizarabe(start_t *start, game_t *game)
{
    sfVector2f pos3 = {1200, 200};
    sfSprite_setTextureRect(game->sal, game->pokerec);
    sfSprite_setPosition(game->sal, pos3);
    if (game->count_rect == 6)
        sfSprite_setColor(game->sal, opacity_base);
    else
        sfSprite_setColor(game->sal, opacity);
    sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
    pos3.x += 100;
    pos3.y -= 100;
    sfText_setString(game->name_text, "Bulbizarabe");
    sfText_setPosition(game->name_text, pos3);
    sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
}

void choose_slave(start_t *start, game_t *game)
{

    game->pokerec.left = 0;
    game->pokerec.width = 500;
    game->pokerec.top = 0;
    game->pokerec.height = 500;
    choose_salamwesh(start, game);
    choose_carapuceau(start, game);
    choose_bulbizarabe(start, game);
}

void game_launch(game_t *game, start_t *start)
{
    if (start->scene == NEW_GAME_START) {
        if (game->load != -1) {
            game->load = -1;
            init_game(game);
        }
        if (game->status == PROF)
            sfRenderWindow_drawSprite(start->my_rpg, game->chen, NULL);
        if (game->status == GENDER)
            display_girl_boy(game, start);
        if (game->status == NAME)
            choose_name(start, game);
        if (game->status == START_AVENTURE)
            choose_slave(start, game);
        sfRenderWindow_drawSprite(start->my_rpg, game->text_box, NULL);
        text_display(game, start);
    }
}
