/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** raycaster
*/

#ifndef RAYCASTER_H
    # define RAYCASTER_H

    # include "player.h"
    # include <SFML/Graphics.h>

typedef enum obstacle_type_s {
    O_WALL,
    O_DOOR,
    O_ITEM_DOOR,
    O_SHOP_DOOR,
    O_BOSS_DOOR,
    O_NONE
} obstacle_type_t;

typedef struct ray_s {
    obstacle_type_t obstacle_type;
    double ray_angle;
    double cos_angle;
    double sin_angle;
    double distance;
    int side;
    int ray_id;
    double hit_x;
    double hit_y;
} ray_t;

typedef struct s_shader {
    sfSprite *render_sprite;
    sfShader *bright_shader;
    sfShader *combine_shader;
    sfRenderTexture *render_texture;
} shader_t;

typedef struct display_s {
    sfRectangleShape *wall;
    sfRectangleShape *shadow;
    sfRectangleShape *final_shape;
    sfRectangleShape *paused_background;
    sfRectangleShape *paused_background_color;
    sfVertexArray *floor_array;
    sfRenderTexture *texture;
    sfTexture *texture_sky;
    sfTexture *texture_wall;
    sfTexture *texture_door;
    sfTexture *texture_door_item;
    sfTexture *texture_door_shop;
    sfTexture *texture_door_boss;
    sfTexture *texture_floor;
    sfTexture *final_texture;
    sfTexture *texture_paused;
    const sfImage *floor_image;
    const sfUint8 *floor_pixels_ptr;
    double texture_scale;
    double texture_scale_tiled;
    shader_t shader;
} display_t;

typedef struct render_s {
    player_t *player;
    sfRenderWindow *window;
    display_t *display;
    double fov;
    double dist_to_proj;
    int window_width;
    int window_height;
    int half_height;
    int half_width;
    int pitch_offset;
} render_t;

void display_rays(void);
void display_ray(render_t *render, ray_t *ray);
void render_frame(render_t *render);

void init_ray(void);
display_t *get_ray(void);
void unload_ray(void);

void project_text(char *text_name, sfVector3f position, render_t *render);

sfVector2f project_point(render_t *render,
    double world_x, double world_y, double world_z);
double calculate_projected_distance(render_t *render,
    double world_x, double world_y, double world_z);
double get_player_dist(double world_x, double world_y, double world_z);

enum obstacle_type_s parse_obstacle_type(int x, int y);

void draw_collectibles(render_t *render);
void draw_items(render_t *render);
void display_entities(render_t *render);
void draw_particles(render_t *render);

void render_shaders(render_t *render, sfRenderTexture *scene_rt);

#endif
