/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** main start menu
*/

#include "rpg.h"

sfVector2f save_pos_text = {730, 450};
sfVector2f scale_text = {2, 2};
sfVector2f prev_posx = {350, 400};
sfVector2f next_posx = {1300, 400};
sfVector2f start_posx = {770, 600};

void current_save_find(start_t *start)
{
    sfText_setScale(start->saves->saveText, scale_text);
    sfText_setFont(start->saves->saveText, start->saves->fontsave);
    sfText_setPosition(start->saves->saveText, save_pos_text);
    start->saves->carac = my_strcmpn("SAVE NAME:", start->saves->save_file, start->saves->carac);
    for (int i = 0; start->saves->save_file[start->saves->carac] != '\n'; start->saves->carac++, i++) {
        start->saves->current_save[i] = start->saves->save_file[start->saves->carac];
    }
    start->saves->carac++;
    sfText_setString(start->saves->saveText, start->saves->current_save);
}

void init_save2(start_t *start)
{
    start->saves->saveText = sfText_create();
    start->saves->fontsave = sfFont_createFromFile("assets/text.ttf");
    start->saves->carac = 0;
    memset(&start->saves->current_save, 0, 256);
    current_save_find(start);
}

void init_save(start_t *start)
{
    int i = 0;
    char buff[256];
    int fd = open("assets/save.txt", O_RDONLY);

    if (fd == -1)
        return 1;
    for (int j = 1; j != -1 && j != 0;) {
        j = read(fd, buff, 256);
        if (j != -1) {
            i += j;
        }
    }
    start->saves->save_file = malloc(sizeof(char) * (i + 1));
    close(fd);
    fd = open("assets/save.txt", O_RDONLY);
    read(fd, start->saves->save_file, i);
    start->saves->file_length = i;
    start->saves->save_file[i] = '\0';
    close(fd);
    init_save2(start);
}

void start_game(start_t *start)
{
    if (my_strcmp("New Game", start->saves->current_save) == 0) {
        memset(&start->saves->current_save, 0, sizeof(start->saves->current_save));
        my_strcpy(start->saves->current_save, "Enter Name");
        start->scene = NEW_GAME_NAME;
        sfText_setString(start->saves->saveText, start->saves->current_save);
    } else
        start->saves->load_save = 1;
}

void is_start_prev_pressed(start_t *start)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(start->my_rpg);

    if ((mouse_pos.x >= start_posx.x && mouse_pos.x <= start_posx.x + 360
    && mouse_pos.y >= start_posx.y && mouse_pos.y <= start_posx.y + 340
    && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) || sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue) {
        sfSound_play(start->buttons->sound);
        start_game(start);
    }
    if ((mouse_pos.x >= prev_posx.x && mouse_pos.x <= prev_posx.x + 240
    && mouse_pos.y >= prev_posx.y && mouse_pos.y <= prev_posx.y + 160 &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) || sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        memset(&start->saves->current_save, 0, sizeof(start->saves->current_save));
        start->saves->carac = my_strcmpd("SAVE NAME:", start->saves->save_file, start->saves->carac, start->saves->file_length);
        start->saves->carac = my_strcmpd("SAVE NAME:", start->saves->save_file, start->saves->carac, start->saves->file_length) + 10;
        for (int i = 0; start->saves->save_file[start->saves->carac] != '\n' &&
        start->saves->carac != -1; start->saves->carac++, i++)
            start->saves->current_save[i] = start->saves->save_file[start->saves->carac];
        sfSound_play(start->buttons->sound);
        sfText_setString(start->saves->saveText, start->saves->current_save);
    }
}

void is_button_pressed(start_t *start)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(start->my_rpg);

    if ((mouse_pos.x >= next_posx.x && mouse_pos.x <= next_posx.x + 240
    && mouse_pos.y >= next_posx.y && mouse_pos.y <= next_posx.y + 160 &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) || sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        sfSound_play(start->buttons->sound);
        memset(&start->saves->current_save, 0, sizeof(start->saves->current_save));
        start->saves->carac = my_strcmpn("SAVE NAME:", start->saves->save_file, start->saves->carac);
        for (int i = 0; start->saves->save_file[start->saves->carac] != '\n' &&
        start->saves->save_file[start->saves->carac] != '\0' && start->saves->carac != -1; start->saves->carac++, i++)
            start->saves->current_save[i] = start->saves->save_file[start->saves->carac];
        if (start->saves->carac == -1) {
            start->saves->carac = 0;
            is_button_pressed(start);
        }
        sfText_setString(start->saves->saveText, start->saves->current_save);
    }
    is_start_prev_pressed(start);
}
