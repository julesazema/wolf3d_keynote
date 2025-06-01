/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ray_displayer
*/

#include <stdio.h>
#include <math.h>
#include "raycaster.h"
#include "wolf.h"

static void append_floor_pixel(const render_t *render, ray_t *ray,
    int y, int pixel_index)
{
    sfVertexArray_append(render->display->floor_array, (sfVertex) {
        .position = (sfVector2f){ray->ray_id, y},
        .color = (sfColor) {
            render->display->floor_pixels_ptr[pixel_index],
            render->display->floor_pixels_ptr[pixel_index + 1],
            render->display->floor_pixels_ptr[pixel_index + 2],
            render->display->floor_pixels_ptr[pixel_index + 3]
        }
    });
}

static void create_floor_rectangle(const render_t *render, ray_t *ray,
    double wall_lowest_point)
{
    double base_row_distance = ((render->player->z * 2 + TILE_SIZE / 2) *
        render->dist_to_proj) / cos(ray->ray_angle - render->player->yaw);
    double row_distance;
    double floor[2];
    int tex_x;
    int tex_y;

    for (int y = wall_lowest_point; y < render->window_height; y += 20) {
        if (y == render->half_height + render->pitch_offset)
            continue;
        row_distance = base_row_distance /
            (y - (render->half_height + render->pitch_offset));
        floor[0] = render->player->x + row_distance * ray->cos_angle;
        floor[1] = render->player->y + row_distance * ray->sin_angle;
        tex_x = (int) (floor[0] * render->display->texture_scale_tiled) & 1023;
        tex_y = (int) (floor[1] * render->display->texture_scale_tiled) & 1023;
        append_floor_pixel(render, ray, y, (tex_y * 1024 + tex_x) * 4);
    }
}

static sfTexture *get_texture_from_obstacle(render_t *render, ray_t *ray)
{
    if (ray->obstacle_type == O_DOOR)
        return (render->display->texture_door);
    if (ray->obstacle_type == O_ITEM_DOOR)
        return (render->display->texture_door_item);
    if (ray->obstacle_type == O_SHOP_DOOR)
        return (render->display->texture_door_shop);
    if (ray->obstacle_type == O_BOSS_DOOR)
        return (render->display->texture_door_boss);
    return (render->display->texture_wall);
}

static void create_line(render_t *render, ray_t *ray,
    double line_top, double line_height)
{
    sfRectangleShape *dest = render->display->wall;
    double wall_hit = ray->side ? ray->hit_x : ray->hit_y;
    int tex_x;

    wall_hit = (wall_hit / TILE_SIZE) - floor(wall_hit / TILE_SIZE);
    tex_x = (int) ((wall_hit) * render->display->texture_scale);
    if (tex_x < 0)
        tex_x = 0;
    if (tex_x >= render->display->texture_scale)
        tex_x = render->display->texture_scale - 1;
    if ((ray->side == 0 && ray->cos_angle > 0) ||
        (ray->side == 1 && ray->sin_angle < 0))
        tex_x = render->display->texture_scale - tex_x;
    sfRectangleShape_setSize(dest, (sfVector2f) {1, line_height});
    sfRectangleShape_setTexture(dest,
        get_texture_from_obstacle(render, ray), sfTrue);
    sfRectangleShape_setPosition(dest, (sfVector2f) {ray->ray_id, line_top});
    sfRectangleShape_setTextureRect(dest, (sfIntRect) {tex_x, 0, 2, 1024});
    sfRenderTexture_drawRectangleShape(render->display->texture, dest, NULL);
}

static void create_shadow(render_t *render, ray_t *ray,
    double line_top, double line_height)
{
    double gamma = 1.0f;
    double shade = fmin(1.0, (ray->distance / 250));

    shade = fmin(1.0, shade * shade);
    shade = pow(shade, 1.0 / gamma);
    sfRectangleShape_setSize(render->display->shadow,
        (sfVector2f) {1, line_height});
    sfRectangleShape_setPosition(render->display->shadow,
        (sfVector2f) {ray->ray_id, line_top});
    sfRectangleShape_setFillColor(render->display->shadow,
        sfColor_fromRGBA(0, 0, 0, shade * 180));
    sfRectangleShape_setTexture(render->display->shadow, NULL, sfFalse);
    sfRenderTexture_drawRectangleShape(render->display->texture,
        render->display->shadow, NULL);
}

void display_ray(render_t *render, ray_t *ray)
{
    player_t *player = render->player;
    double vertical_offset;
    double horizon = 0;
    double line_height = 0;
    double line_top = 0;
    double inv_distance = 1 / ray->distance;

    vertical_offset = (player->z * inv_distance) * render->dist_to_proj;
    line_height = (TILE_SIZE * inv_distance) * render->dist_to_proj;
    horizon = render->half_height + vertical_offset + render->pitch_offset;
    line_top = horizon + vertical_offset - (line_height / 2);
    create_line(render, ray, line_top, line_height);
    create_shadow(render, ray, line_top, line_height);
    sfVertexArray_clear(render->display->floor_array);
    create_floor_rectangle(render, ray, line_top + line_height);
    sfRenderTexture_drawVertexArray(render->display->texture,
        render->display->floor_array, NULL);
}

void render_frame(render_t *render)
{
    sfRenderTexture_display(render->display->texture);
    render->display->final_texture =
        (sfTexture *) sfRenderTexture_getTexture(render->display->texture);
    render_shaders(render, render->display->texture);
}
