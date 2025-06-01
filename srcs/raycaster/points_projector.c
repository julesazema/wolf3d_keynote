/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** points_projector
*/

#include <stdio.h>
#include <tgmath.h>
#include <SFML/System/Vector2.h>
#include "raycaster.h"

sfVector2f project_point(render_t *render,
    double world_x, double world_y, double world_z)
{
    player_t *player = render->player;
    double rel_x = world_x - player->x;
    double rel_y = world_y - player->y;
    double rel_z = world_z - (player->z * 2 + TILE_SIZE / 2);
    double cam_x = rel_x * cos(-player->yaw) - rel_y * sin(-player->yaw);
    double cam_y = rel_x * sin(-player->yaw) + rel_y * cos(-player->yaw);
    double fov_factor = render->half_width / tan(render->fov / 2);
    double screen_x;
    double screen_y;

    if (cam_x <= 0.01)
        return ((sfVector2f) {-10000, -10000});
    screen_x = render->half_width + (cam_y / cam_x) * fov_factor;
    screen_y = render->half_height - (rel_z / cam_x) * fov_factor
        + render->pitch_offset;
    return (sfVector2f) {(float)screen_x, (float)screen_y};
}

double calculate_projected_distance(render_t *render,
    double world_x, double world_y, double world_z)
{
    player_t *player = render->player;
    double rel_x = world_x - player->x;
    double rel_y = world_y - player->y;
    double cam_x = rel_x * cos(-player->yaw) - rel_y * sin(-player->yaw);

    (void)world_z;
    return (cam_x);
}
