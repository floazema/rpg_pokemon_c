/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main body rpg, game loop ...
*/

#include "rpg.h"


static const char str[] = "Bonjour, je suis maitre nico tu me \nregarde mal tu cherche la bagarre ?\n viens te battre";
static const char str2[] = "Salut aventurier possede 6 pokemons\net je te donnerai une surprise";
static const char str3[] = "Ok tu es suffisament fort maintenant\n prend mon pokemon pour t'aider à\nbattre maître nico le mechant pedago";

char *strncpd(char *str, char *str2, int n)
{
    for (int i = n, j = 0; str2[j] != '\0'; i++, j++) {
        str[i] = str2[j];
    }
    return str;
}

char *inser_str(char *str, char *str2, int n)
{
    int j = n;
    int i = n;
    char *temp = malloc(sizeof(char) * my_strlen(str));

    for (; str[j] != '\n'; j++);
    for (int k = 0; str[j] != '\0';j++, k++)
        temp[k] = str[j];
    for (int k = 0; str2[k] != '\0'; k++, i++)
        str[i] = str2[k];
    for (int k = 0; temp[k] != '\0'; k++, i++)
        str[i] = temp[k];
    return str;
}

void save_game(game_t *game, start_t *start)
{
    const char *filename = "assets/save.txt";
    int fd = open(filename, O_WRONLY);
    int i = my_strlen(start->saves->save_file);

    if (fd == -1)
        return 1;
    start->saves->carac = 0;
    if (start->saves->carac = my_strcmpn(start->saves->current_save, start->saves->save_file, start->saves->carac) == -1) {
        start->saves->save_file = strncpd(start->saves->save_file, "SAVE NAME:", i);
        i += 10;
        start->saves->save_file = strncpd(start->saves->save_file, start->saves->current_save, i);
        i += my_strlen(start->saves->current_save);
        start->saves->save_file = strncpd(start->saves->save_file, "\nSEXE:\nPOSX:\nPOSY:\nSCENE1:\nSCENE2:\n", i);
        i += 25;
    }
    start->scene = WORLD;
    start->saves->carac = my_strcmpn(start->saves->current_save, start->saves->save_file, start->saves->carac);
    start->saves->carac = my_strcmpn("SEXE:", start->saves->save_file, start->saves->carac);
    start->saves->save_file = inser_str(start->saves->save_file, my_itoa(game->sexe_perso), start->saves->carac);
    start->saves->carac = my_strcmpn("POSX:", start->saves->save_file, start->saves->carac);
    start->saves->save_file = inser_str(start->saves->save_file, my_itoa(game->pos_x), start->saves->carac);
    start->saves->carac = my_strcmpn("POSY:", start->saves->save_file, start->saves->carac);
    start->saves->save_file = inser_str(start->saves->save_file, my_itoa(game->pos_y), start->saves->carac);
    start->saves->carac = my_strcmpn("SCENE1:", start->saves->save_file, start->saves->carac);
    start->saves->save_file = inser_str(start->saves->save_file, my_itoa(game->map), start->saves->carac);
    start->saves->carac = my_strcmpn("SCENE2:", start->saves->save_file, start->saves->carac);
    start->saves->save_file = inser_str(start->saves->save_file, my_itoa(game->status), start->saves->carac);
    start->saves->carac = my_strcmpn("POKEMON:", start->saves->save_file, start->saves->carac);
    for (int i = 0; i != game->j; i++) {
        start->saves->save_file = inser_str(start->saves->save_file, my_itoa(game->pokemon[i].id), start->saves->carac);
        start->saves->carac += my_strlen(my_itoa(game->pokemon[i].id));
        start->saves->save_file = inser_str(start->saves->save_file, ",", start->saves->carac);
        start->saves->carac++;
        start->saves->save_file = inser_str(start->saves->save_file, my_itoa(game->pokemon[i].level), start->saves->carac);
        start->saves->carac += my_strlen(my_itoa(game->pokemon[i].level));
        start->saves->save_file = inser_str(start->saves->save_file, ",", start->saves->carac);
        start->saves->carac++;
    }
    start->saves->carac += my_strlen(my_itoa(game->stats));
    start->saves->save_file[start->saves->carac + 1] = '\0';
    write(fd, start->saves->save_file, my_strlen(start->saves->save_file));
    close(fd);
}

void menu_detect(game_t *game, start_t *start)
{
    sfVector2f set_pos_menu = { 1100, 300 };
    static sfVector2f button_pos = {1283, 457};
    sfVector2f pos_save = {1320, 560};
    sfVector2f pos_resume = {1485, 560};
    sfVector2f pos_equipe = {1300, 463};
    sfVector2f pos_menu = {1485, 463};
    sfVector2f postext = {300, 900};
    sfVector2f pos_fin = {500, 300};

    if (start->scene == FIN) {
        sfText_setString(game->name_text, "Bravo tu as fini le jeu !!!!");
        sfText_setPosition(game->name_text, pos_fin);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
    }
    if (start->scene == MENU && game->cbt != SWAP) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
            button_pos.x = 1283;
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
            button_pos.y = 457;
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
            button_pos.x = 1480;
        if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
            button_pos.y = 555;
        if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue && button_pos.x == 1283 && button_pos.y == 555)
            save_game(game, start);
        if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue && button_pos.x == 1480 && button_pos.y == 555)
            start->scene = WORLD;
        if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue && button_pos.x == 1283 && button_pos.y == 457)
            game->cbt = SWAP;
        if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue && button_pos.x == 1480 && button_pos.y == 457) {
            sfRenderWindow_destroy(start->my_rpg);
            init_start(start, game);
            start->scene = 0;
        }
        game->menurect.top = 50;
        game->menurect.width = 750;
        game->menurect.height = 500;
        sfSprite_setTextureRect(game->menu, game->menurect);
        sfSprite_setPosition(game->menu, set_pos_menu);
        sfRenderWindow_drawSprite(start->my_rpg, game->menu, NULL);
        game->menurect.top = 0;
        game->menurect.width = 200;
        game->menurect.height = 50;
        sfSprite_setTextureRect(game->menu, game->menurect);
        sfSprite_setPosition(game->menu, button_pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->menu, NULL);
        sfText_setString(game->name_text, "Save");
        sfText_setPosition(game->name_text, pos_save);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfText_setString(game->name_text, "Resume");
        sfText_setPosition(game->name_text, pos_resume);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfText_setString(game->name_text, "Equipe");
        sfText_setPosition(game->name_text, pos_equipe);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfText_setString(game->name_text, "Menu");
        sfText_setPosition(game->name_text, pos_menu);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
    }
    if (start->scene == BOSS) {
        sfText_setString(game->name_text, str);
        sfText_setPosition(game->name_text, postext);
        sfRenderWindow_drawSprite(start->my_rpg, game->text_box, NULL);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
    }
    if (game->quest == 1 || game->quest == 2 && start->scene == QUETE) {
        sfText_setString(game->name_text, str3);
        sfText_setPosition(game->name_text, postext);
        sfRenderWindow_drawSprite(start->my_rpg, game->text_box, NULL);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        game->pokemon[game->j].level = 50;
        game->pokemon[game->j].id = 16;
        game->j++;
        game->quest = 2;
    }
    if (start->scene == QUETE && game->quest == 0) {
        sfText_setString(game->name_text, str2);
        sfText_setPosition(game->name_text, postext);
        sfRenderWindow_drawSprite(start->my_rpg, game->text_box, NULL);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
    }
}

void create_sprite(char *path, sfSprite **sprite, sfTexture **texture,
sfVector2f *basepos)
{
    sfVector2f no_pos = {0, 0};

    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    if (basepos == NULL) {
        sfSprite_setPosition(*sprite, no_pos);
    } else
        sfSprite_setPosition(*sprite, *basepos);
}

char *put_save(start_t *start)
{
    char *temp = NULL;
    int i;

    temp = malloc(256);
    for (i = 0; start->saves->save_file[start->saves->carac] != '\n' &&
    start->saves->save_file[start->saves->carac] != '\0'; i++, start->saves->carac++) {
        temp[i] = start->saves->save_file[start->saves->carac];
    }
    temp[i] = '\0';
    return temp;
}

void reset_perso(game_t *game, start_t *start)
{
    sfVector2f scale_base = {1, 1};
    sfVector2f midle = {950, 480};

    game->persorect.top = game->sexe_perso;
    game->persorect.width = 65;
    game->persorect.height = 60;
    game->persorect.left = 0;
    sfSprite_setPosition(game->perso, midle);
    sfSprite_setScale(game->perso, scale_base);
}

void fight_start(game_t *game, start_t *start)
{
    sfVector2f pos = {1000, 130};
    sfVector2f pos2 = {100, 640};
    sfVector2f pos1 = {1450, 180};
    sfVector2f sal_pos = {450, 500};
    sfVector2f lv1 = {100, 740};
    sfVector2f lv2 = {1450, 280};
    sfVector2f action_pos = {500, 930};
    sfVector2f scale = {4, 4};
    sfVector2f perso_pos = {0, 500};
    sfVector2f captxt = {360, 950};
    sfVector2f pos_dmg = {245, 699};
    sfVector2f pos_dmg2 = {1603, 234};
    static int j = 1;
    static int i = 0;
    char str1[400] = "/";
    char str2[64] = "/";
    char str[100] = "Lv.";

    if (game->quest == 0 && game->j >= 6) {
        game->quest = 1;
    }
    if (start->scene == FIGHT) {
        sfRenderWindow_drawSprite(start->my_rpg, game->fight, NULL);
        if (game->death == game->j + 1) {
            start->scene = WORLD;
            game->cbt = SELECT;
        }
    }
    if (start->scene == FIGHT && game->cbt == SELECT) {
        if (game->pokemon[game->k].hp - (game->pokemon[game->k].level * 10 + 100) >= 0) {
            game->cbt = SWAP;
            game->death += 1;
        }
        game->enemy_dmg = game->pokemon[game->k].hp;
        draw_pokemon(game, pos2, game->pokemon[game->k].id, sal_pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->box, NULL);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
        draw_pokemon(game, pos1, game->alea, pos);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
        sfText_setString(game->name_text, my_strcat(str, my_itoa(game->pokemon[game->k].level)));
        sfText_setPosition(game->name_text, lv1);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        str[3] = '\0', str[4] = '\0', str[5] = '\0';
        sfText_setString(game->name_text, my_strcat(str, my_itoa(game->alealv)));
        sfText_setPosition(game->name_text, lv2);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        lv1.x += 200;
        lv2.x += 200;
        sfText_setPosition(game->name_text, lv2);
        sfText_setString(game->name_text, my_strcat(my_itoa(game->alealv * 10 + 100 - game->ally_dmg), my_strcat(str1, my_itoa(game->alealv * 10 + 100))));
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfText_setPosition(game->name_text, lv1);
        sfText_setString(game->name_text, my_strcat(my_itoa(game->pokemon[game->k].level * 10 + 100 - game->enemy_dmg), my_strcat(str2, my_itoa(game->pokemon[game->k].level * 10 + 100))));
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
        sfRenderWindow_drawSprite(start->my_rpg, game->text_box, NULL);
        sfText_setString(game->name_text, "Attaque");
        sfText_setPosition(game->name_text, action_pos);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfText_setString(game->name_text, "Switch");
        action_pos.x += 400;
        sfText_setPosition(game->name_text, action_pos);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfText_setString(game->name_text, "Fuite");
        action_pos.y += 70;
        action_pos.x -= 400;
        sfText_setPosition(game->name_text, action_pos);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfText_setString(game->name_text, "Capture");
        action_pos.x += 400;
        i = 0;
        sfText_setPosition(game->name_text, action_pos);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyA) && game->pos_rect.x == 480 && game->pos_rect.y == 980
        && game->alealv <= 50)
            start->scene = WORLD;
        sfSprite_setPosition(game->redrec, game->pos_rect);
        sfRenderWindow_drawSprite(start->my_rpg, game->redrec, NULL);
        game->dmgrect.top = 0;
        game->dmgrect.width = 500;
        sfSprite_setTextureRect(game->dmg, game->dmgrect);
        sfSprite_setPosition(game->dmg, pos_dmg2);
        sfRenderWindow_drawSprite(start->my_rpg, game->dmg, NULL);
        game->dmgrect.top = 25;
        game->dmgrect.width = (((game->alealv * 10 + 100) - game->ally_dmg) / (game->alealv * 10 + 100)) * 300;
        sfSprite_setTextureRect(game->dmg, game->dmgrect);
        sfSprite_setPosition(game->dmg, pos_dmg2);
        sfRenderWindow_drawSprite(start->my_rpg, game->dmg, NULL);
        game->dmgrect.top = 0;
        game->dmgrect.width = 500;
        sfSprite_setTextureRect(game->dmg, game->dmgrect);
        sfSprite_setPosition(game->dmg, pos_dmg);
        sfRenderWindow_drawSprite(start->my_rpg, game->dmg, NULL);
        game->dmgrect.top = 25;
        game->dmgrect.width = (((game->pokemon[game->k].level * 10 + 100) - game->enemy_dmg) / (game->pokemon[game->k].level * 10 + 100)) * 300;
        sfSprite_setTextureRect(game->dmg, game->dmgrect);
        sfSprite_setPosition(game->dmg, pos_dmg);
        sfRenderWindow_drawSprite(start->my_rpg, game->dmg, NULL);
        if (game->ally_dmg - (game->alealv * 10 + 100) >= 0) {
            start->scene = WORLD;
            game->pokemon[game->k].level += 3;
        }
        if (game->ally_dmg - (game->alealv * 10 + 100) >= 0 && game->alealv >= 50) {
            start->scene = FIN;
        }
    }
    if (start->scene == FIGHT && game->cbt == CAPTURE) {
        if (i == 0) {
            game->pos_ball.x = 200;
            game->pos_ball.y = 710;
            j = 1;
            if (game->sexe_perso > 500)
                game->persorect.top = 760;
            else
                game->persorect.top = 260;
            game->persorect.width = 169;
            game->persorect.height = 170;
            game->persorect.left = 0;
            i = 1;
            sfSprite_setPosition(game->perso, perso_pos);
        }
        game->perso_t = sfClock_getElapsedTime(game->perso_c);
        game->perso_s = game->perso_t.microseconds / 1000000.0;
        if (game->perso_s >= 0.2 && i != 2) {
            game->persorect.left += 169;
            sfClock_restart(game->perso_c);
            game->pos_ball.x += 210;
            game->pos_ball.y -= 55;
            if (game->persorect.left > 700) {
                game->persorect.left = 0;
                i = 2;
            }
        }
        if (game->perso_s >= 0.2 && j % 20 != 0) {
            if (j % 2 == 0)
                sfSprite_setRotation(game->ball, 15);
            else
                sfSprite_setRotation(game->ball, -15);
            j += 1;
            sfClock_restart(game->perso_c);
        }
        sfSprite_setPosition(game->ball, game->pos_ball);
        sfSprite_setScale(game->perso, scale);
        sfSprite_setTextureRect(game->perso, game->persorect);
        sfRenderWindow_drawSprite(start->my_rpg, game->perso, NULL);
        if (j != 60)
            sfRenderWindow_drawSprite(start->my_rpg, game->ball, NULL);
        draw_pokemon(game, pos2, game->pokemon[game->k].id, sal_pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
        if (i != 2 || j == 60) {
            draw_pokemon(game, pos1, game->alea, pos);
            sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
        }
        if (j == 20) {
            srand(time(NULL));
            game->aleacap = (rand() % (100));
            if (game->ally_dmg / ((game->alealv * 10) + 100) * 100 >= game->aleacap)
                j = 40;
            else
                j = 60;
        }
        if (j % 20 == 0) {
            sfText_setPosition(game->name_text, captxt);
            sfSprite_setRotation(game->ball, 0);
            sfRenderWindow_drawSprite(start->my_rpg, game->text_box, NULL);
            if (j == 40) {
                sfText_setString(game->name_text, "Capture reussie, bien joue !");
                game->ally_dmg = 0;
                game->enemy_dmg = 0;
                if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
                    game->j++;
                    game->pokemon[game->j].hp = 0;
                    game->pokemon[game->j].id = game->alea;
                    game->pokemon[game->j].level = game->alealv;
                    reset_perso(game, start);
                    start->scene = WORLD;
                }
            } else {
                sfText_setString(game->name_text, "Capture rate, reessaie !");
                if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue) {
                    game->pokemon[game->k].hp += (5 + (game->alealv));
                    reset_perso(game, start);
                    game->cbt = SELECT;
                }
            }
            sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        }
    }
    if (game->cbt == SWAP) {
        char lv[10] = "Lv.";
        char hp[20] = "hp: ";
        char atk[20] = "dmg: ";
        sfVector2f sprite_scale = {0.3, 0.3};
        sfVector2f basic_scale = {1, 1};
        sfVector2f sprite_pos = {750, 400};
        sfVector2f name_pos = {900, 420};
        sfRenderWindow_drawSprite(start->my_rpg, game->tab, NULL);
        sfSprite_setScale(game->sal, sprite_scale);
        draw_pokemon(game, name_pos, game->pokemon[game->k].id, sprite_pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->sal, NULL);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        name_pos.y += 40;
        sfText_setPosition(game->name_text, name_pos);
        sfText_setString(game->name_text, my_strcat(lv, my_itoa(game->pokemon[game->k].level)));
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        sfSprite_setScale(game->sal, basic_scale);
        name_pos.y += 40;
        sfText_setString(game->name_text, my_strcat(hp, my_itoa(game->pokemon[game->k].level * 10 + 100) - game->pokemon[game->k].hp));
        sfText_setPosition(game->name_text, name_pos);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        name_pos.y += 40;
        sfText_setString(game->name_text, my_strcat(atk, my_itoa((10 + (game->pokemon[game->k].level * 2)))));
        sfText_setPosition(game->name_text, name_pos);
        sfRenderWindow_drawText(start->my_rpg, game->name_text, NULL);
        if (game->death == game->j + 1)
            start->scene = WORLD;
    }
}

void load_save(game_t *game, start_t *start)
{
    if (start->saves->load_save == 1) {
        game->perso_c = sfClock_create();
        game->text_c = sfClock_create();
        game->name_text = sfText_create();
        game->pokefont = sfFont_createFromFile("assets/pokemon.ttf");
        sfText_setColor(game->name_text, sfBlack);
        sfText_setFont(game->name_text, game->pokefont);
        create_sprite("assets/text_box.png", &game->text_box, &game->texture_text_box,
        NULL);
        create_sprite("assets/perso.png", &game->perso, &game->texture_perso, NULL);
        start->saves->carac = 0;
        start->saves->carac = my_strcmpn(start->saves->current_save, start->saves->save_file, start->saves->carac);
        start->saves->carac = my_strcmpn("SEXE:", start->saves->save_file, start->saves->carac);
        game->sexe_perso = my_atoi(put_save(start));
        start->saves->carac = my_strcmpn("POSX:", start->saves->save_file, start->saves->carac);
        game->pos_x = my_atoi(put_save(start));
        start->saves->carac = my_strcmpn("POSY:", start->saves->save_file, start->saves->carac);
        game->pos_y = my_atoi(put_save(start));
        start->saves->carac = my_strcmpn("SCENE1:", start->saves->save_file, start->saves->carac);
        game->map = my_atoi(put_save(start));
        start->saves->carac = my_strcmpn("SCENE2:", start->saves->save_file, start->saves->carac);
        game->status = my_atoi(put_save(start));
        start->scene = WORLD;
        start->saves->load_save = 2;
    }
}

int my_rpg(void)
{
    start_t *start = malloc(sizeof(start_t));
    game_t *game = malloc(sizeof(game_t));

    if (init_start(start, game) == 84)
        return 84;
    while (sfRenderWindow_isOpen(start->my_rpg)) {
        sfRenderWindow_clear(start->my_rpg, sfBlack);
        load_save(game, start);
        manage_event(start, game);
        handle_start_menu(start);
        game_launch(game, start);
        draw_map(game, start);
        draw_perso(game, start);
        menu_detect(game, start);
        fight_start(game, start);
        sfRenderWindow_display(start->my_rpg);
    }
}

int helper(int ac, char **argv)
{
    if (ac > 1)
        if (my_strcmp(argv[1], "-h") == 0) {
            return EXIT_HELPER;
        }
    return 1;
}

int main(int argc, char **argv)
{
    if (helper(argc, argv) == EXIT_HELPER)
        return EXIT_HELPER;
    my_rpg();
    return 0;
}
