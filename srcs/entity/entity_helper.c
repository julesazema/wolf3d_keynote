/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_helper
*/

#include "entity.h"
#include "player.h"

int is_entity_outside_room(entity_t *entity)
{
    room_t *room;

    room = &get_run()->floors[entity->floor_id].rooms[entity->room_id];
    if (entity->x < 0)
        return (1);
    if (entity->y < 0)
        return (1);
    if (entity->x > room->width * TILE_SIZE)
        return (1);
    if (entity->y > room->height * TILE_SIZE)
        return (1);
    return (0);
}
