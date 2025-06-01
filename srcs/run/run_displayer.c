/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** run_displayer
*/

#include <math.h>
#include <stdio.h>

#include "run.h"

int contains_obstacle(double x, double y)
{
    run_t *run = get_run();
    room_t *current_room;

    if (is_door(x, y))
        return (0);
    if (x <= 0 || y <= 0)
        return (1);
    current_room = &run->floors[run->current_floor].rooms[run->current_room];
    if (x >= current_room->width || y >= current_room->height)
        return (1);
    return (current_room->matrix[(int)y][(int)x] == 'W');
}

double get_dist_corner(double x, double y)
{
    double room_w = get_current_room(get_run())->width;
    double room_h = get_current_room(get_run())->height;
    double d1 = hypot(x - 0, y - 0);
    double d2 = hypot(x - room_w, y - 0);
    double d3 = hypot(x - 0, y - room_h);
    double d4 = hypot(x - room_w, y - room_h);

    return fmin(fmin(d1, d2), fmin(d3, d4)) / hypot(room_w, room_h);
}

room_t *get_door_room(double x, double y)
{
    run_t *run = get_run();
    floor_t *floor = get_current_floor(run);
    room_t *current_room = &floor->rooms[run->current_room];
    int center_x = current_room->width / 2;
    int center_y = current_room->height / 2;

    if ((int)x == center_x && y <= 0)
        return (get_room(floor,
            current_room->floor_x, current_room->floor_y - 1));
    if ((int)x == center_x && y >= current_room->height)
        return (get_room(floor,
            current_room->floor_x, current_room->floor_y + 1));
    if ((int)y == center_y && x <= 0)
        return (get_room(floor,
            current_room->floor_x - 1, current_room->floor_y));
    if ((int)y == center_y && x >= current_room->width)
        return (get_room(floor,
            current_room->floor_x + 1, current_room->floor_y));
    return (NULL);
}

int is_door(double x, double y)
{
    return (get_door_room(x, y) != NULL);
}
