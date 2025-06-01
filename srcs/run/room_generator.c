/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** room_generator
*/

#include <stdlib.h>

#include "collectible.h"
#include "entity.h"
#include "item.h"
#include "player.h"
#include "run.h"
#include "wolf.h"

list_t *generate_room_collectibles(void)
{
    list_t *result = NULL;
    int i;

    i = 0;
    while (i < 3) {
        drop_collectible(&result,
            (double) (i + 1) * (5.0f / 4) * TILE_SIZE,
            3.0f / 2 * TILE_SIZE);
        i++;
    }
    return (result);
}

list_t *generate_room_items(void)
{
    list_t *result = NULL;
    dropped_item_t *tmp;
    int i;

    i = 0;
    while (i < 1) {
        tmp = malloc(sizeof(dropped_item_t));
        if (!tmp)
            return (result);
        tmp->x = 5.0f / 2 * TILE_SIZE;
        tmp->y = 3.0f / 2 * TILE_SIZE;
        tmp->z = 0;
        tmp->ref = get_random_item();
        ft_lstadd_back(&result, ft_createnode(tmp, NULL));
        i++;
    }
    return (result);
}

room_t generate_room_content(room_type_t room_type, int index,
    int x, int y)
{
    room_t result;

    result.type = room_type;
    result.width = 5;
    result.height = 3;
    generate_room_matrix(&result);
    result.id = index;
    result.floor_x = x;
    result.floor_y = y;
    result.visited = 0;
    result.finished = 1;
    result.collectibles = NULL;
    result.items = NULL;
    result.entities = NULL;
    return (result);
}

static int is_empty_unlinked(floor_t *floor, int x, int y)
{
    if (get_room(floor, x, y))
        return (0);
    if (count_links(floor, x, y) != 1)
        return (0);
    return (1);
}

static int assign_room(floor_t *floor,
    room_type_t type, int x, int y)
{
    if (is_empty_unlinked(floor, x, y)) {
        floor->rooms[floor->nb_rooms] =
            generate_room_content(type, floor->nb_rooms, x, y);
        floor->rooms[floor->nb_rooms].floor_id = floor->floor_id;
        floor->nb_rooms += 1;
        return (1);
    }
    return (0);
}

static int has_newroom(floor_t *floor)
{
    room_t *current;
    int i = 0;

    while (i < floor->nb_rooms) {
        current = &floor->rooms[i];
        if (current->type != CLASSIC_ROOM) {
            i++;
            continue;
        }
        if (is_empty_unlinked(floor, current->floor_x + 1, current->floor_y))
            return (1);
        if (is_empty_unlinked(floor, current->floor_x - 1, current->floor_y))
            return (1);
        if (is_empty_unlinked(floor, current->floor_x, current->floor_y + 1))
            return (1);
        if (is_empty_unlinked(floor, current->floor_x, current->floor_y - 1))
            return (1);
        i++;
    }
    return (0);
}

room_t *create_unlinked_room(floor_t *floor, room_type_t type)
{
    room_t *tmp;
    room_t *result = &floor->rooms[floor->nb_rooms];

    if (!has_newroom(floor))
        return (NULL);
    tmp = &floor->rooms[get_random(floor->nb_rooms)];
    while (tmp->type != CLASSIC_ROOM)
        tmp = &floor->rooms[get_random(floor->nb_rooms)];
    if (assign_room(floor, type, tmp->floor_x + 1, tmp->floor_y))
        return (result);
    if (assign_room(floor, type, tmp->floor_x - 1, tmp->floor_y))
        return (result);
    if (assign_room(floor, type, tmp->floor_x, tmp->floor_y + 1))
        return (result);
    if (assign_room(floor, type, tmp->floor_x, tmp->floor_y - 1))
        return (result);
    return (create_unlinked_room(floor, type));
}
