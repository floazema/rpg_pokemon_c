/*
** EPITECH PROJECT, 2022
** draw_game
** File description:
** draw_game
*/

#include "rpg.h"

int draw_tile_element(game_t *game, start_t *start, char *buff, int i)
{
    if (buff[i] == 'a' && buff[i + 1] == '1') {
        game->insiderect.left = 0;
        game->insiderect.top = 0;
        game->insiderect.height = 33;
        game->insiderect.width = 33;
        sfSprite_setTextureRect(game->inside, game->insiderect);
        sfRenderWindow_drawSprite(start->my_rpg, game->inside, NULL);
        i += 2;
    }
    if (buff[i] == 'a' && buff[i + 1] == '2') {
        game->insiderect.left = 0;
        game->insiderect.top = 33;
        game->insiderect.height = 64;
        game->insiderect.width = 32;
        game->pos.y -= 32;
        sfSprite_setPosition(game->inside, game->pos);
        game->pos.y += 32;
        sfSprite_setTextureRect(game->inside, game->insiderect);
        sfRenderWindow_drawSprite(start->my_rpg, game->inside, NULL);
        i += 2;
    }
    if (buff[i] == 'a' && buff[i + 1] == '4') {
        game->insiderect.left = 0;
        game->insiderect.top = 140;
        game->insiderect.height = 70;
        game->insiderect.width = 70;
        game->pos.y -= 40;
        game->pos.x -= 40;
        sfSprite_setPosition(game->inside, game->pos);
        game->pos.y += 40;
        game->pos.x += 40;
        sfSprite_setTextureRect(game->inside, game->insiderect);
        sfRenderWindow_drawSprite(start->my_rpg, game->inside, NULL);
        i += 2;
    }
    if (buff[i] == 'a' && buff[i + 1] == '5') {
        game->insiderect.left = 0;
        game->insiderect.top = 214;
        game->insiderect.height = 32;
        game->insiderect.width = 92;
        game->pos.x -= 64;
        sfSprite_setPosition(game->inside, game->pos);
        game->pos.x += 64;
        sfSprite_setTextureRect(game->inside, game->insiderect);
        sfRenderWindow_drawSprite(start->my_rpg, game->inside, NULL);
        i += 2;
    }
    if (buff[i] == 'a' && buff[i + 1] == '6') {
        game->insiderect.left = 0;
        game->insiderect.top = 246;
        game->insiderect.height = 64;
        game->insiderect.width = 32;
        game->pos.y -= 28;
        sfSprite_setPosition(game->inside, game->pos);
        game->pos.y += 28;
        sfSprite_setTextureRect(game->inside, game->insiderect);
        sfRenderWindow_drawSprite(start->my_rpg, game->inside, NULL);
        i += 2;
    }
    if (buff[i] == 'a' && buff[i + 1] == '7') {
        game->extrect.left = 0;
        game->extrect.top = 0;
        game->extrect.height = 32;
        game->extrect.width = 32;
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    if (buff[i] == 'a' && buff[i + 1] == '8') {
        game->extrect.left = 32;
        game->extrect.top = 0;
        game->extrect.height = 32;
        game->extrect.width = 32;
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfSprite_setPosition(game->ext, game->pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    if (buff[i] == 'a' && buff[i + 1] == '9') {
        game->extrect.left = 64;
        game->extrect.top = 0;
        game->extrect.height = 32;
        game->extrect.width = 32;
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfSprite_setPosition(game->ext, game->pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == '1') {
        game->extrect.left = 96;
        game->extrect.top = 0;
        game->extrect.height = 32;
        game->extrect.width = 32;
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfSprite_setPosition(game->ext, game->pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == '2') {
        game->extrect.left = 128;
        game->extrect.top = 0;
        game->extrect.height = 32;
        game->extrect.width = 32;
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfSprite_setPosition(game->ext, game->pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == '3') {
        game->extrect.left = 160;
        game->extrect.top = 0;
        game->extrect.height = 32;
        game->extrect.width = 32;
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfSprite_setPosition(game->ext, game->pos);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == '4') {
        game->extrect.left = 0;
        game->extrect.top = 38;
        game->extrect.height = 190;
        game->extrect.width = 140;
        game->pos.x -= 118;
        game->pos.y -= 168;
        sfSprite_setPosition(game->ext, game->pos);
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        game->pos.x += 118;
        game->pos.y += 168;
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == '5') {
        game->extrect.left = 192;
        game->extrect.top = 0;
        game->extrect.height = 64;
        game->extrect.width = 60;
        game->pos.y -= 64;
        sfSprite_setPosition(game->ext, game->pos);
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        game->pos.y += 64;
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == '6') {
        game->extrect.left = 256;
        game->extrect.top = 0;
        game->extrect.height = 36;
        game->extrect.width = 36;
        sfSprite_setPosition(game->ext, game->pos);
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == '8') {
        game->insiderect.left = 0;
        game->insiderect.top = 300;
        game->insiderect.height = 70;
        game->insiderect.width = 70;
        game->pos.y -= 40;
        game->pos.x -= 40;
        sfSprite_setPosition(game->inside, game->pos);
        game->pos.y += 40;
        game->pos.x += 40;
        sfSprite_setTextureRect(game->inside, game->insiderect);
        sfRenderWindow_drawSprite(start->my_rpg, game->inside, NULL);
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == '9') {
        game->extrect.left = 300;
        game->extrect.top = 0;
        game->extrect.height = 70;
        game->extrect.width = 60;
        game->pos.y -= 40;
        game->pos.x -= 10;
        sfSprite_setPosition(game->ext, game->pos);
        game->pos.y += 40;
        game->pos.x += 10;
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    if (buff[i] == 'b' && buff[i + 1] == 'a') {
        game->extrect.left = 400;
        game->extrect.top = 0;
        game->extrect.height = 70;
        game->extrect.width = 60;
        game->pos.y -= 40;
        game->pos.x -= 10;
        sfSprite_setPosition(game->ext, game->pos);
        game->pos.y += 40;
        game->pos.x += 10;
        sfSprite_setTextureRect(game->ext, game->extrect);
        sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
        i += 2;
    }
    return i;
}

int put_multiple(game_t *game, start_t *start, int i, char *buff)
{
    i++;
    for (; buff[i] != ']';) {
        i = draw_tile_element(game, start, buff, i);
    }
    i++;
    return i;
}

void draw_element(char *buff, game_t *game, start_t *start)
{
    int i = 0;

    if ((start->scene == WORLD || start->scene == MENU || start->scene == BOSS
    || start->scene == QUETE)) {
        game->pos.x = game->pos_x;
        game->pos.y = game->pos_y;
        for (i = 0; i != my_strlen(buff) && buff[i] != '\0';) {
            if (buff[i] == '\n') {
                game->pos.x = game->pos_x;
                game->pos.y += 32;
                i += 1;
            }
            if (buff[i] == 'n' && buff[i + 1] == 'o') {
                i += 2;
                game->pos.x += 32;
            }
            if (buff[i] == '[') {
                sfSprite_setPosition(game->inside, game->pos);
                i = put_multiple(game, start, i, buff);
                game->pos.x += 32;
            }
            if (buff[i] == 'a' && buff[i + 1] == '1') {
                game->insiderect.left = 0;
                game->insiderect.top = 0;
                game->insiderect.height = 33;
                game->insiderect.width = 33;
                sfSprite_setTextureRect(game->inside, game->insiderect);
                sfSprite_setPosition(game->inside, game->pos);
                sfRenderWindow_drawSprite(start->my_rpg, game->inside, NULL);
                i += 2;
                game->pos.x += 32;
            }
            if (buff[i] == 'a' && buff[i + 1] == '3') {
                game->insiderect.left = 0;
                game->insiderect.top = 96;
                game->insiderect.height = 44;
                game->insiderect.width = 48;
                game->pos.y -= 12;
                game->pos.x -= 12;
                sfSprite_setPosition(game->inside, game->pos);
                game->pos.y += 12;
                game->pos.x += 12;
                sfSprite_setTextureRect(game->inside, game->insiderect);
                sfRenderWindow_drawSprite(start->my_rpg, game->inside, NULL);
                i += 2;
                game->pos.x += 32;
            }
            if (buff[i] == 'a' && buff[i + 1] == '7') {
                game->extrect.left = 0;
                game->extrect.top = 0;
                game->extrect.height = 32;
                game->extrect.width = 32;
                sfSprite_setTextureRect(game->ext, game->extrect);
                sfSprite_setPosition(game->ext, game->pos);
                sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
                i += 2;
                game->pos.x += 32;
            }
            if (buff[i] == 'a' && buff[i + 1] == '8') {
                game->extrect.left = 32;
                game->extrect.top = 0;
                game->extrect.height = 32;
                game->extrect.width = 32;
                sfSprite_setTextureRect(game->ext, game->extrect);
                sfSprite_setPosition(game->ext, game->pos);
                sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
                i += 2;
                game->pos.x += 32;
            }
            if (buff[i] == 'a' && buff[i + 1] == '9') {
                game->extrect.left = 64;
                game->extrect.top = 0;
                game->extrect.height = 32;
                game->extrect.width = 32;
                sfSprite_setTextureRect(game->ext, game->extrect);
                sfSprite_setPosition(game->ext, game->pos);
                sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
                i += 2;
                game->pos.x += 32;
            }
            if (buff[i] == 'b' && buff[i + 1] == '1') {
                game->extrect.left = 96;
                game->extrect.top = 0;
                game->extrect.height = 32;
                game->extrect.width = 32;
                sfSprite_setTextureRect(game->ext, game->extrect);
                sfSprite_setPosition(game->ext, game->pos);
                sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
                i += 2;
                game->pos.x += 32;
            }
            if (buff[i] == 'b' && buff[i + 1] == '2') {
                game->extrect.left = 128;
                game->extrect.top = 0;
                game->extrect.height = 32;
                game->extrect.width = 32;
                sfSprite_setTextureRect(game->ext, game->extrect);
                sfSprite_setPosition(game->ext, game->pos);
                sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
                i += 2;
                game->pos.x += 32;
            }
            if (buff[i] == 'b' && buff[i + 1] == '3') {
                game->extrect.left = 160;
                game->extrect.top = 0;
                game->extrect.height = 32;
                game->extrect.width = 32;
                sfSprite_setTextureRect(game->ext, game->extrect);
                sfSprite_setPosition(game->ext, game->pos);
                sfRenderWindow_drawSprite(start->my_rpg, game->ext, NULL);
                i += 2;
                game->pos.x += 32;
            }
        }
    }
}

void draw_map(game_t *game, start_t *start)
{
    static char buff[100000];
    int fd = 0;

    if (fd == -1)
        return 1;
    if (game->stats != -1 && game->stats != 6 && game->stats != 7
    && (start->scene == WORLD || start->scene == BOSS)) {
        init_world(game, start);
        game->pos.x = 0;
        game->pos.y = 0;
        create_sprite("assets/tileset_ext.png", &game->ext, &game->texture_ext, NULL);
        create_sprite("assets/tileset_int.png", &game->inside, &game->texture_inside, NULL);
    }
    if (game->map == HOUSE_START && game->i == 1) {
        fd = open("assets/house.txt", O_RDONLY);
        memset(&buff, 0, my_strlen(buff));
        read(fd, buff, (10000));
        close(fd);
        game->i = -1;
    }
    if (game->map == CITY && game->i == 2) {
        memset(&buff, 0, my_strlen(buff));
        fd = open("assets/city.txt", O_RDONLY);
        read(fd, buff, (50000));
        close(fd);
        game->i = -1;
    }
    draw_element(buff, game, start);
}
