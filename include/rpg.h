/*
** EPITECH PROJECT, 2021
** mystruct
** File description:
** struct init
*/

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include "../lib/my/my.h"
#include "struct.h"
#include <string.h>

#ifndef _DEFENDER_
    #define _DEFENDER_
    #define EXIT_HELPER 0
    void manage_event(start_t *start, game_t *game);
    int init_start(start_t *start, game_t *game);
    void handle_start_menu(start_t *start);
    void create_sprite(char *path, sfSprite **sprite, sfTexture **texture,
        sfVector2f *basepos);
    void do_parralax_cloud_bird(start_t *start);
    void do_moove_bird(start_t *start);
    void button_display(start_t *start);
    void init_save(start_t *start);
    void display_text_save(start_t *start);
    void is_button_pressed(start_t *start);
    int my_strcmpd(char const *s1, char const *s2, int i, int k);
    void manage_key (sfKeyCode code, char *str);
    void start_save_display(start_t *start);
    void glow_start(start_t *start);
    void is_new_game(start_t *start);
    int gen_sound(buttons_t *button);
    void game_launch(game_t *game, start_t *start);
    void draw_perso(game_t *game, start_t *start);
    void choose_name(start_t *start, game_t *game);
    char *put_save(start_t *start);
    void init_world(game_t *game, start_t *start);
    void draw_map(game_t *game, start_t *start);
    void is_fight(start_t *start, game_t *game);
#endif
