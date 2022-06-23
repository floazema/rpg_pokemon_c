/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main body rpg, game loop ...
*/

#include "rpg.h"
#include <time.h>

static const sfVector2f midle_screen = {950, 480};
static const sfVector2f scale_game = {1, 1};
static const sfColor no_opacity = {255, 255, 255, 255};
static const sfVector2f text_pos_seta = {200, 850};
static const sfVector2f text_scale = {0.6, 0.6};
static const char hitbox_house[40][60] = {
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOXOOXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOXOOXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOXOOXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOXOOXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOXXXXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOBBBXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOBBBXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOBBXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOBBXXXXXXXXXXXXXXXXXXXXXOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOXXXOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOXXXOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOAAAOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
};

static const char hitbox_city[60][120] = {
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOBBCYCBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOBBCYCBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOBBCCCBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXBBBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXBBBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXBBBBBBBBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXBBBOOOOBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXBBXOOOOBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXBBXOOOOBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXBBXOOOOBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXBBXAXXOBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXDDBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXDDBBXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
    {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"},
};

void draw_pokemon(game_t *game, sfVector2f pos2, int id, sfVector2f pos)
{
    game->pokerec.width = 500;
    game->pokerec.height = 500;
    if (id == 1) {
        sfText_setString(game->name_text, "Salamwesh");
        game->pokerec.left = 0;
        game->pokerec.top = 0;
    }
    if (id == 2) {
        sfText_setString(game->name_text, "Reptinsel");
        game->pokerec.left = 0;
        game->pokerec.top = 500;
    }
    if (id == 3) {
        sfText_setString(game->name_text, "Dracofeutre");
        game->pokerec.left = 0;
        game->pokerec.top = 1000;
    }
    if (id == 4) {
        sfText_setString(game->name_text, "Carapuceau");
        game->pokerec.left = 500;
        game->pokerec.top = 0;
    }
    if (id == 5) {
        sfText_setString(game->name_text, "Thortank");
        game->pokerec.left = 500;
        game->pokerec.top = 1000;
    }
    if (id == 6) {
        sfText_setString(game->name_text, "Bulbizarbi");
        game->pokerec.left = 1000;
        game->pokerec.top = 0;
    }
    if (id == 7) {
        sfText_setString(game->name_text, "Herbebizare");
        game->pokerec.left = 1000;
        game->pokerec.top = 500;
    }
    if (id == 8) {
        sfText_setString(game->name_text, "Florizarbi");
        game->pokerec.left = 1000;
        game->pokerec.top = 1000;
    }
    if (id == 9) {
        sfText_setString(game->name_text, "Rockaillou");
        game->pokerec.left = 1500;
        game->pokerec.top = 0;
    }
    if (id == 10) {
        sfText_setString(game->name_text, "Gravalenchon");
        game->pokerec.left = 1500;
        game->pokerec.top = 500;
    }
    if (id == 11) {
        sfText_setString(game->name_text, "Grolemur");
        game->pokerec.left = 1500;
        game->pokerec.top = 1000;
    }
    if (id == 12) {
        sfText_setString(game->name_text, "Taupineur");
        game->pokerec.left = 2000;
        game->pokerec.top = 0;
    }
    if (id == 13) {
        sfText_setString(game->name_text, "Triopineur");
        game->pokerec.left = 2000;
        game->pokerec.top = 500;
    }
    if (id == 14) {
        sfText_setString(game->name_text, "Pickachuck");
        game->pokerec.left = 2500;
        game->pokerec.top = 0;
    }
    if (id == 15) {
        sfText_setString(game->name_text, "Lapyroman");
        game->pokerec.left = 3000;
        game->pokerec.top = 0;
    }
    if (id == 16) {
        sfText_setString(game->name_text, "Mr_Meme");
        game->pokerec.left = 3000;
        game->pokerec.top = 500;
    }
    if (id == 17) {
        sfText_setString(game->name_text, "Wejdedene");
        game->pokerec.left = 3500;
        game->pokerec.top = 0;
    }
    if (id == 18) {
        sfText_setString(game->name_text, "Macrondoudou");
        game->pokerec.left = 4000;
        game->pokerec.top = 0;
    }
    if (id == 19) {
        sfText_setString(game->name_text, "Grodoudoune");
        game->pokerec.left = 4000;
        game->pokerec.top = 500;
    }
    if (id == 20) {
        sfText_setString(game->name_text, "Ratatata");
        game->pokerec.left = 4500;
        game->pokerec.top = 0;
    }
    sfText_setPosition(game->name_text, pos2);
    sfSprite_setPosition(game->sal, pos);
    sfSprite_setTextureRect(game->sal, game->pokerec);
}

void set_pokemon_random(game_t *game, start_t *start)
{
    game->alea = -1;

    srand(time(NULL));
    game->alea = (rand() % (20)) + 1;
}

void init_world(game_t *game, start_t *start)
{
    sfVector2f tab = {600, 200};

    game->quest = 0;
    game->pos_rect.x = 480;
    game->k = 0;
    game->death = 0;
    game->pos_rect.y = 910;
    game->pos_ball.x = 200;
    game->pos_ball.y = 710;
    game->j = 0;
    game->pokemon = malloc(sizeof(pokemon_t) * 1000);
    sfSprite_setPosition(game->perso, midle_screen);
    sfSprite_setScale(game->perso, scale_game);
    sfSprite_setColor(game->perso, no_opacity);
    game->persorect.left = 0;
    game->persorect.top = game->sexe_perso;
    game->persorect.width = 65;
    game->persorect.height = 60;
    game->stats = -1;
    game->is_anim = 0;
    if (game->map == HOUSE_START)
        game->i = 1;
    if (game->map == CITY)
        game->i = 2;
    if (start->saves->load_save != 2) {
        game->pos_x = 0;
        game->pos_y = 0;
    }
    create_sprite("assets/tableau.png", &game->tab, &game->texture_tab, &tab);
    create_sprite("assets/pokeball.png", &game->ball, &game->texture_ball, NULL);
    create_sprite("assets/rect.png", &game->redrec, &game->texture_redrec, NULL);
    create_sprite("assets/menu.png", &game->menu, &game->texture_menu, NULL);
    create_sprite("assets/fight.png", &game->fight, &game->texture_fight, NULL);
    create_sprite("assets/pokemon.png", &game->sal, &game->texture_sal, NULL);
    create_sprite("assets/heal box.png", &game->box, &game->texture_box, NULL);
    create_sprite("assets/damage.png", &game->dmg, &game->texture_dmg, NULL);
    sfSprite_setPosition(game->text_box, text_pos_seta);
    sfSprite_setScale(game->text_box, text_scale);
    sfSprite_setTextureRect(game->perso, game->persorect);
    if (game->count_rect == 6) {
        game->pokemon[0].id = 6;
    } else {
        game->pokemon[0].id = game->count_rect + 1;
    }
    game->pokemon[0].level = 5;
    game->pokemon[0].hp = 0;
    game->dmgrect.left = 0;
    game->dmgrect.top = 0;
    game->dmgrect.height = 25;
    game->dmgrect.width = 300;
}

void is_fight(start_t *start, game_t *game)
{
    int alea = -1;

    if (game->map == CITY ) {
        if (hitbox_city[17 - (game->pos_y / 32)][30 - (game->pos_x / 32)] == 'B') {
            srand(time(NULL));
            alea = (rand() % (100));
        }
        if (alea >= 0 && alea <= 20) {
            start->scene = FIGHT;
            game->cbt = 0;
            set_pokemon_random(game, start);
            srand(time(NULL));
            game->enemy_dmg = 0;
            game->ally_dmg = 0;
            game->alealv = (rand() % (30)) + 1;
        }
    }
}

void anim_perso(game_t *game)
{
    static int i = 0;
    static int j = 0;
    static int k = 0;

    if (hitbox_house[16 - (game->pos_y / 32)][30 - (game->pos_x / 32)] == 'B'
    && game->map == HOUSE_START && sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
        for (int i = 0; i != game->j + 1; i++) {
            game->pokemon[i].hp = 0;
            game->death = 0;
        }
    }
    if (game->perso_s >= 0.07 && game->is_anim != 0 && game->map == HOUSE_START) {
        game->persorect.left += 65;
        if (i == 0) {
            if (game->is_anim == 1 && hitbox_house[16 - (game->pos_y / 32)][29 - (game->pos_x / 32)] != 'O'
            && hitbox_house[16 - (game->pos_y / 32)][29 - (game->pos_x / 32)] != 'Y')
                k = 1;
            if (game->is_anim == 4 && hitbox_house[17 - (game->pos_y / 32)][30 - (game->pos_x / 32)] != 'O'
            && hitbox_house[17 - (game->pos_y / 32)][30 - (game->pos_x / 32)] != 'Y')
                k = 1;
            if (game->is_anim == 2 && hitbox_house[15 - (game->pos_y / 32)][30 - (game->pos_x / 32)] != 'O'
            && hitbox_house[15 - (game->pos_y / 32)][30 - (game->pos_x / 32)] != 'Y')
                k = 1;
            if (game->is_anim == 3 && hitbox_house[16 - (game->pos_y / 32)][31 - (game->pos_x / 32)] != 'O'
            && hitbox_house[16 - (game->pos_y / 32)][31 - (game->pos_x / 32)] != 'Y')
                k = 1;
            if (game->is_anim == 4 && hitbox_house[17 - (game->pos_y / 32)][30 - (game->pos_x / 32)] == 'A') {
                game->map = CITY;
                game->pos_y = -192;
                game->pos_x = 256;
                game->i = 2;
            }
        }
        i += 1;
        if (game->is_anim == 1 && k == 1)
            game->pos_x += 8;
        if (game->is_anim == 2 && k == 1)
            game->pos_y += 8;
        if (game->is_anim == 4 && k == 1)
            game->pos_y -= 8;
        if (game->is_anim == 3 && k == 1)
            game->pos_x -= 8;
        if (i >= 4) {
            i = 0;
            k = 0;
            game->persorect.left = 0;
            game->is_anim = 0;
        }
        sfSprite_setTextureRect(game->perso, game->persorect);
        sfClock_restart(game->perso_c);
    }
    if (game->perso_s >= 0.07 && game->is_anim != 0 && game->map == CITY) {
        game->persorect.left += 65;
        if (i == 0) {
            if (game->is_anim == 1 && hitbox_city[16 - (game->pos_y / 32)][29 - (game->pos_x / 32)] != 'O' &&
            game->is_anim == 1 && hitbox_city[16 - (game->pos_y / 32)][29 - (game->pos_x / 32)] != 'Y')
                j = 1;
            if (game->is_anim == 4 && hitbox_city[16 - (game->pos_y / 32)][30 - (game->pos_x / 32)] != 'O' &&
            game->is_anim == 4 && hitbox_city[17 - (game->pos_y / 32)][30 - (game->pos_x / 32)] != 'Y')
                j = 1;
            if (game->is_anim == 2 && hitbox_city[15 - (game->pos_y / 32)][30 - (game->pos_x / 32)] != 'O' &&
            game->is_anim == 2 && hitbox_city[15 - (game->pos_y / 32)][30 - (game->pos_x / 32)] != 'Y')
                j = 1;
            if (game->is_anim == 3 && hitbox_city[16 - (game->pos_y / 32)][31 - (game->pos_x / 32)] != 'O' &&
            game->is_anim == 3 && hitbox_city[16 - (game->pos_y / 32)][31 - (game->pos_x / 32)] != 'Y')
                j = 1;
            if (game->is_anim == 2 && hitbox_city[16 - (game->pos_y / 32)][30 - (game->pos_x / 32)] == 'A') {
                game->map = HOUSE_START;
                game->pos_x = 192;
                game->pos_y = -352;
                game->i = 1;
            }
        }
        if (game->is_anim == 1 && j == 1)
            game->pos_x += 8;
        if (game->is_anim == 2 && j == 1)
            game->pos_y += 8;
        if (game->is_anim == 4 && j == 1)
            game->pos_y -= 8;
        if (game->is_anim == 3 && j == 1)
            game->pos_x -= 8;
        i += 1;
        if (i >= 4) {
            i = 0;
            j = 0;
            game->persorect.left = 0;
            game->is_anim = 0;
        }
        sfSprite_setTextureRect(game->perso, game->persorect);
        sfClock_restart(game->perso_c);
    }
}

void moove_perso(game_t *game)
{
    game->perso_t = sfClock_getElapsedTime(game->perso_c);
    game->perso_s = game->perso_t.microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && game->is_anim == 0) {
        game->persorect.top = 60 + game->sexe_perso;
        sfSprite_setTextureRect(game->perso, game->persorect);
        game->is_anim = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && game->is_anim == 0) {
        game->persorect.top = 180 + game->sexe_perso;
        sfSprite_setTextureRect(game->perso, game->persorect);
        game->is_anim = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && game->is_anim == 0) {
        game->persorect.top = 120 + game->sexe_perso;
        sfSprite_setTextureRect(game->perso, game->persorect);
        game->is_anim = 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && game->is_anim == 0) {
        game->persorect.top = 0 + game->sexe_perso;
        sfSprite_setTextureRect(game->perso, game->persorect);
        game->is_anim = 4;
    }
    anim_perso(game);
}

void draw_perso(game_t *game, start_t *start)
{
    if (start->scene == WORLD) {
        moove_perso(game);
        if (hitbox_city[17 - (game->pos_y / 32)][30 - (game->pos_x / 32)] == 'C'
        && game->map == CITY) {
            game->alealv = 100;
        }
        if (hitbox_city[17 - (game->pos_y / 32)][30 - (game->pos_x / 32)] == 'D'
        && game->map == CITY && sfKeyboard_isKeyPressed(sfKeyA)) {
            game->stats = 6;
        }
    }
    if (start->scene == WORLD || start->scene == MENU ||start->scene == BOSS || start->scene == QUETE) {
        sfRenderWindow_drawSprite(start->my_rpg, game->perso, NULL);
    }
}
