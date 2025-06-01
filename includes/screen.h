/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** screen
*/

#ifndef SCREEN_H
    # define SCREEN_H

typedef enum {
    S_MENU = 1,
    S_INTRO = 2,
    S_GAME = 3,
    S_STATS = 4,
    S_OPTIONS = 5,
    S_CONTROLS = 6,
    S_MAPMAKER = 7,
    S_PAUSED = 8
} screen_type_t;

typedef struct s_screen {
    screen_type_t type;
    void (*load_func)();
    void (*draw_func)();
    void (*unload_func)();
} screen_t;

typedef struct s_list_sprites {
    char *name_sprite;
    int id;
} list_sprites_t;

void load_menu_screen(void);
void draw_menu_screen(void);
void unload_menu_screen(void);
void init_sprite_list(char *name, int i);
void init_sprites(void);

void load_intro_screen(void);
void draw_intro_screen(void);
void unload_intro_screen(void);

void load_game_screen(void);
void draw_game_screen(void);
void unload_game_screen(void);

void load_stats_screen(void);
void draw_stats_screen(void);
void unload_stats_screen(void);

void load_options_screen(void);
void draw_options_screen(void);
void unload_options_screen(void);
void draw_options_texts(void);

void load_controls_screen(void);
void draw_controls_screen(void);
void unload_controls_screen(void);

void load_mapmaker_screen(void);
void draw_mapmaker_screen(void);
void unload_mapmaker_screen(void);

void load_paused_screen(void);
void draw_paused_screen(void);
void unload_paused_screen(void);

void set_screen(screen_type_t type);
screen_t *get_screen(void);
void unload_screen(void);

#endif
