/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** wolf.h
*/

#ifndef WORLD_H
    # define WORLD_H

    # include <SFML/Audio.h>
    # include <SFML/Window.h>
    # include <SFML/Graphics.h>
    # include <SFML/System.h>

typedef enum button_state_s {
    IDLE,
    HOVER,
    CLICKED,
    DISABLED
} button_state_t;

typedef enum resource_type_s {
    TEXTURE,
    SOUND,
    FONT,
    MUSIC
} resource_type_t;

typedef struct resource_s {
    char name[128];
    void *data;
    resource_type_t type;
} resource_t;

typedef struct sprite_s {
    char name[128];
    sfSprite *sprite;
    resource_t *resource;
} sprite_t;

typedef struct text_s {
    char name[128];
    sfText *text;
    int hidden;
} text_t;

typedef struct button_s {
    char name[128];
    int hidden;
    resource_t *texture;
    sfSprite *sprite;
    button_state_t state;
    void (*on_click) (void);
} button_t;

typedef struct runnable_s {
    char name[128];
    sfClock *clock;
    double time_repeat;
} runnable_t;

void init_window(int width, int height, char *title, int full_screen);
sfRenderWindow *get_window(void);
void destroy_window(void);

void start_loop(void);

void on_event(sfEvent *event);

void load_resources(void);
void unload_resources(void);
void load_resource(char *name, char *path, resource_type_t type);
resource_t *get_resource(char *name);

sprite_t *create_sprite(char *name, int x, int y, char *resource_name);
void unload_sprites(void);
sprite_t *get_sprite(char *name);

void draw_sprite(char *sprite_name);
void scale_sprite(char *sprite_name, float factor);
void rescale_sprite(char *sprite_name, float factor);
void resize_sprite(char *sprite_name, float x, float y);
void rotate_sprite(char *sprite_name, float angle);
void move_sprite(char *sprite_name, float x, float y);
void center_sprite(char *sprite_name, float x, float y);
void place_sprite(char *sprite_name, float x, float y);
sfVector2f get_sprite_size(char *sprite_name);

void create_button(char *resource_name, int x, int y,
    void (*on_click) (void));
void unload_buttons(void);
button_t *get_button(char *name);
void update_buttons(int mouse_x, int mouse_y, int state);

void hide_button(char *button_name);
void show_button(char *button_name);
void scale_button(char *button_name, float scale);
void draw_button(char *button_name);

void create_text(char *name, char *text, char *font_name);
text_t *get_text(char *name);
void draw_texts(void);
void unload_texts(void);

void change_text(char *text_name, char *content);
void move_text(char *text_name, int x, int y);
void scale_text(char *text_name, int scale);
void colorize_text(char *text_name, sfColor color);
void outline_text(char *text_name, float thickness, sfColor color);

void draw_text(char *text_name);
void show_text(char *text_name);
void hide_text(char *text_name);
void center_text(char *text_name, int x, int y);
void center_text_origin(char *text_name);

void create_menu_text(char *name, char *text, int scale);

void create_clock(char *name, float time_repeat);
runnable_t *get_clock(char *name);
void unload_clocks(void);

int is_clock_elapsed(char *clock_name);
void restart_clock(char *clock_name);

void update_mouse_position(int mouse_x, int mouse_y);

unsigned int get_window_width(void);
unsigned int get_window_height(void);

void play_sound(char *resource_name);
void play_sound_pitched(char *resource_name, float pitch);

void play_music(char *resource_name);
void set_music_volume(char *resource_name, float volume);
void stop_music(char *resource_name);
void set_music_playing_offset(char *resource_name, double offset);
int get_music_status(char *resource_name);

void ft_putstr(char *str);
void ft_putstr_fd(int fd, char *str);
void ft_putnbr_fd(int fd, int nb);
void ft_strcpy(char *dest, char *src);
void ft_strncpy(char *dest, char *src, int n);
int ft_strlen(char *str);
char *ft_strnstr(const char *big, const char *little, size_t len);
char **ft_split(char *str, char *sep);
void ft_freesplit(char **split);
int ft_strcmp(char *s1, char *s2);
char *ft_strdup(char *src);
char *ft_strndup(char *src, int n);
int is_mouse_inrange(sfFloatRect box, int mouse_x, int mouse_y);
int ft_atoi(char *str);
char *ft_itoa(int nb);
int get_random(int len);
char *ft_itoad(int nb, char *buffer, int buffer_size);
char *ft_strcat(char *dest, char *src);
int ft_strncmp(char *s1, char *s2, int n);

int extract_signed4bit(int val);

int exists_file(char *file_path);

int is_graphical(char *envp[]);

void set_screenshot(void);

#endif
