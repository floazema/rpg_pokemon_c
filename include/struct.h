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

#ifndef __MY_STRUCT__
    #define __MY_STRUCT__$
    enum game_scene_s {
        START_MENU,
        START_GAME,
        HTP,
        NEW_GAME_NAME,
        NEW_GAME_START,
        WORLD,
        MENU,
        FIGHT,
        BOSS,
        QUETE,
        FIN,
    };
    enum start_status_s {
        PROF,
        GENDER,
        NAME,
        START_AVENTURE,
    };
    enum map_pos_s {
        HOUSE_START,
        CITY,
    };
    enum fight_status_s {
        SELECT,
        CAPTURE,
        SWAP,
        ATTACK,
    };
    typedef struct saves_s {
        char *save_file;
        sfText *saveText;
        sfFont *fontsave;
        char current_save[256];
        int carac;
        int file_length;
        int load_save;
    } saves_t;
    typedef struct birds_s {
        float bird_s;
        sfClock *bird_c;
        sfTime bird_t;
        sfIntRect bird_rect;
        sfSprite *birds_start;
        sfTexture *texture_birds_start;
        sfVector2f bird_pos[6];
    } birds_t;
    typedef struct clouds_s {
        sfTexture *texture_cloud_start;
        sfSprite *cloud_start;
        sfSprite *cloud_start_2;
        sfClock *cloud_c;
        sfTime cloud_t;
        float cloud_s;
    } clouds_t;
    typedef struct buttons_s {
        sfSprite *button_start;
        sfIntRect button_rect;
        sfTexture *texture_button_start;
        sfSound *sound;
        sfSoundBuffer *soundbuffer;
    } buttons_t;
    typedef struct start_s {
        enum game_scene_s scene;
        sfRenderWindow *my_rpg;
        sfTexture *texture_menu_background;
        sfSprite *menu_background;
        sfTexture *texture_help;
        sfSprite *help;
        birds_t *birds;
        clouds_t *clouds;
        buttons_t *buttons;
        saves_t *saves;
    } start_t;
    typedef struct pokemon {
        int rect;
        int id;
        int xp;
        float level;
        int hp;
        int hp_max;
        int attack;
        int defense;
        int name;
    } pokemon_t;
    typedef struct game_s {
        sfSprite *dmg;
        sfTexture *texture_dmg;
        sfIntRect dmgrect;
        pokemon_t *pokemon;
        sfIntRect pokerec;
        sfSprite *redrec;
        sfTexture *texture_redrec;
        sfSprite *tab;
        sfTexture *texture_tab;
        sfSprite *perso;
        sfTexture *texture_perso;
        sfSprite *fight;
        sfTexture *texture_box;
        sfSprite *ball;
        sfTexture *texture_ball;
        sfSprite *box;
        sfTexture *texture_fight;
        sfSprite *sal;
        sfTexture *texture_sal;
        sfSprite *menu;
        int death;
        sfIntRect menurect;
        sfTexture *texture_menu;
        sfSprite *chen;
        sfTexture *texture_chen;
        sfIntRect persorect;
        sfIntRect insiderect;
        sfIntRect extrect;
        sfTexture *texture_text_box;
        sfSprite *text_box;
        sfTexture *texture_inside;
        sfSprite *inside;
        sfTexture *texture_ext;
        sfSprite *ext;
        sfText *prestext;
        sfText *name_text;
        sfFont *pokefont;
        sfVector2f pos_rect;
        float ally_dmg;
        float enemy_dmg;
        int j;
        int quest;
        int count_rect;
        int load;
        int k;
        int sexe_perso;
        int text_char;
        int persoleft;
        int alea;
        float text_s;
        int count;
        int pos_x;
        int pos_y;
        float alealv;
        int aleacap;
        int stats;
        char name[15];
        sfClock *text_c;
        sfTime text_t;
        sfClock *perso_c;
        sfTime perso_t;
        float perso_s;
        int is_anim;
        char display[2048];
        char stock[2048];
        sfVector2f pos;
        sfVector2f pos_ball;
        enum start_status_s status;
        enum map_pos_s map;
        enum fight_status_s cbt;
        int i;
    } game_t;
#endif
