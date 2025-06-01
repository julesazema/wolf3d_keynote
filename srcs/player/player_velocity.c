/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_velocity
*/

#include <math.h>
#include <stdio.h>

#include "collectible.h"
#include "item.h"
#include "player.h"
#include "run.h"
#include "wolf.h"

static void apply_z_velocity(player_t *player)
{
    if (player->velocity_z < 0 && player->z <= 0) {
        player->velocity_z = 0;
        return;
    }
    player->z += player->velocity_z;
    player->velocity_z -= GRAVITY;
    if (player->z <= 0) {
        player->z = 0;
        player->velocity_z = 0;
    }
}

static room_t *get_next_room(double x, double y)
{
    room_t *current_room;

    current_room = get_current_room(get_run());
    if (x >= current_room->width)
        return (get_room(get_current_floor(get_run()),
            current_room->floor_x + 1, current_room->floor_y));
    if (x <= 0)
        return (get_room(get_current_floor(get_run()),
            current_room->floor_x - 1, current_room->floor_y));
    if (y >= current_room->height)
        return (get_room(get_current_floor(get_run()),
            current_room->floor_x, current_room->floor_y + 1));
    if (y <= 0)
        return (get_room(get_current_floor(get_run()),
            current_room->floor_x, current_room->floor_y - 1));
    return (NULL);
}

static void check_room_changes(double x, double y)
{
    room_t *next_room;

    next_room = get_next_room(x, y);
    if (!next_room)
        return;
    launch_room(next_room->id);
}

static dropped_collectible_t *get_dropped_pickup(room_t *room,
    double x, double y, double z)
{
    list_t *list;
    dropped_collectible_t *tmp;

    (void)z;
    list = room->collectibles;
    while (list) {
        tmp = list->data;
        if (fabs(x - tmp->x) < (double)TILE_SIZE / 2 &&
            fabs(y - tmp->y) < (double)TILE_SIZE / 2)
            return (tmp);
        list = list->next;
    }
    return (NULL);
}

static dropped_item_t *get_dropped_item(room_t *room,
    double x, double y, double z)
{
    list_t *list;
    dropped_item_t *tmp;

    (void)z;
    list = room->items;
    while (list) {
        tmp = list->data;
        if (fabs(x - tmp->x) < (double)TILE_SIZE / 2 &&
            fabs(y - tmp->y) < (double)TILE_SIZE / 2)
            return (tmp);
        list = list->next;
    }
    return (NULL);
}

static void check_movement_actions(double x, double y, double z)
{
    room_t *current_room;
    dropped_collectible_t *pickup;
    dropped_item_t *item;

    current_room = get_current_room(get_run());
    item = get_dropped_item(current_room, x, y, z);
    if (item)
        pickup_item(item);
    pickup = get_dropped_pickup(current_room, x, y, z);
    if (pickup)
        pickup_collectible(pickup);
}

static int can_move(player_t *player, double x, double y)
{
    double dest_x;
    double dest_y;

    dest_x = (player->x + x) * TILE_SIZE_INV;
    dest_y = (player->y + y) * TILE_SIZE_INV;
    if (contains_obstacle(dest_x, dest_y))
        return (0);
    if (is_door(dest_x, dest_y))
        return (get_current_room(get_run())->finished);
    return (1);
}

static void apply_velocity(player_t *player)
{
    double old_x;
    double old_y;

    old_x = player->velocity_x;
    old_y = player->velocity_y;
    player->velocity_x /= 1.3;
    player->velocity_y /= 1.3;
    if (can_move(player, old_x, 0))
        player->x += old_x;
    if (can_move(player, 0, old_y))
        player->y += old_y;
    if (fabs(player->velocity_x) < 0.1)
        player->velocity_x = 0;
    if (fabs(player->velocity_y) < 0.1)
        player->velocity_y = 0;
}

static void apply_sides_velocities(player_t *player)
{
    apply_velocity(player);
    check_movement_actions(player->x, player->y, player->z);
    check_room_changes(player->x * TILE_SIZE_INV, player->y * TILE_SIZE_INV);
}

void apply_player_velocities(void)
{
    apply_sides_velocities(get_player());
    apply_z_velocity(get_player());
}
