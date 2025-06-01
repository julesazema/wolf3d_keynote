/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** raycaster
*/

#include <math.h>
#include "wolf.h"
#include "raycaster.h"
#include "run.h"
#include "tear.h"
#include "particle.h"

/*static ray_t cast_ray(render_t *render, int i)
{
    ray_t result;

    result.ray_angle = render->player->yaw - (render->fov / 2) +
        ((double)i / render->window_width) * render->fov;
    result.cos_angle = cos(result.ray_angle);
    result.sin_angle = sin(result.ray_angle);
    result.distance = 0;
    while (result.distance < 2000) {
        result.hit_x = render->player->x + result.cos_angle * result.distance;
        result.hit_y = render->player->y + result.sin_angle * result.distance;
        if (contains_obstacle((int)(result.hit_x * TILE_SIZE_INV),
            (int)(result.hit_y * TILE_SIZE_INV)))
            break;
        result.distance++;
    }
    result.distance =
        result.distance * cos(result.ray_angle - render->player->yaw);
    if (result.distance < 1)
        result.distance = 1;
    result.side = result.hit_x > result.hit_y;
    return (result);
}*/

static void cast_angle(render_t *render, ray_t *dest, int i,
    double delta_dist[2])
{
    dest->ray_angle = render->player->yaw - (render->fov / 2) +
        ((double)i / render->window_width) * render->fov;
    dest->cos_angle = cos(dest->ray_angle);
    dest->sin_angle = sin(dest->ray_angle);
    delta_dist[0] = fabs(1.0 / dest->cos_angle);
    delta_dist[1] = fabs(1.0 / dest->sin_angle);
}

static void cast_distance(render_t *render, ray_t *dest,
    double side_dist[2], double delta_dist[2])
{
    if (dest->side == 0)
        dest->distance = (side_dist[0] - delta_dist[0]);
    else
        dest->distance = (side_dist[1] - delta_dist[1]);
    dest->hit_x = render->player->x + dest->cos_angle * dest->distance;
    dest->hit_y = render->player->y + dest->sin_angle * dest->distance;
    dest->distance =
        dest->distance * cos(dest->ray_angle - render->player->yaw);
    if (dest->distance < 1)
        dest->distance = 1;
}

static void setup_steps(ray_t *result,
    double side_dist[2], double delta_dist[2], int step[2])
{
    int map[2] = {(int)(get_player()->x), (int)(get_player()->y)};

    if (result->cos_angle < 0) {
        step[0] = -1;
        side_dist[0] = (get_player()->x - map[0]) * delta_dist[0];
    } else {
        step[0] = 1;
        side_dist[0] = (map[0] + 1.0 - get_player()->x) * delta_dist[0];
    }
    if (result->sin_angle < 0) {
        step[1] = -1;
        side_dist[1] = (get_player()->y - map[1]) * delta_dist[1];
    } else {
        step[1] = 1;
        side_dist[1] = (map[1] + 1.0 - get_player()->y) * delta_dist[1];
    }
}

static int iterate_cast(double side_dist[2], double delta_dist[2],
    int map[2], int step[2])
{
    if (side_dist[0] < side_dist[1]) {
        side_dist[0] += delta_dist[0];
        map[0] += step[0];
        return (0);
    }
    side_dist[1] += delta_dist[1];
    map[1] += step[1];
    return (1);
}

static int is_obstacle(double x, double y)
{
    return (is_door(x, y) || contains_obstacle(x, y));
}

static ray_t cast_ray(render_t *render, int i)
{
    ray_t result;
    double delta_dist[2];
    double side_dist[2];
    int map[2] = {(int)(render->player->x), (int)(render->player->y)};
    int step[2];

    cast_angle(render, &result, i, delta_dist);
    setup_steps(&result, side_dist, delta_dist, step);
    while (1) {
        result.side = iterate_cast(side_dist, delta_dist, map, step);
        if (is_obstacle(map[0] * TILE_SIZE_INV, map[1] * TILE_SIZE_INV)) {
            result.obstacle_type = parse_obstacle_type(map[0] * TILE_SIZE_INV,
                map[1] * TILE_SIZE_INV);
            break;
        }
    }
    cast_distance(render, &result, side_dist, delta_dist);
    return (result);
}

void cast_rays(render_t *render)
{
    ray_t current_ray;
    int i;

    i = 0;
    while (i < render->window_width) {
        current_ray = cast_ray(render, i);
        current_ray.ray_id = i;
        display_ray(render, &current_ray);
        i++;
    }
    display_entities(render);
    draw_items(render);
    draw_collectibles(render);
    draw_particles(render);
    draw_projectiles(render);
}

void display_rays(void)
{
    render_t render;

    render.player = get_player();
    render.display = get_ray();
    render.window = get_window();
    render.window_height = (int) get_window_height();
    render.window_width = (int) get_window_width();
    render.half_height = render.window_height / 2;
    render.half_width = render.window_width / 2;
    render.fov = FOV * (M_PI / 180);
    render.pitch_offset = (render.player->pitch / 180.0) *
        ((double) render.window_height / 2);
    render.dist_to_proj = (render.half_height * 1.25) / tan(FOV / 2.0);
    sfVertexArray_clear(render.display->floor_array);
    cast_rays(&render);
    render_frame(&render);
}
