/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_death
*/

#include <stdio.h>

#include "entity.h"
#include "player.h"

static int is_boss(entity_type_t type)
{
    if (type == E_LOKI)
        return 1;
    if (type == E_KING_FLY)
        return 1;
    return 0;
}

void unlock_next_floor(room_t *current)
{
    create_entity(current, E_LADDER, (sfVector3f){(current->width / 2) *
        TILE_SIZE, (current->height / 2) * TILE_SIZE, 40});
    current->finished = 1;
}

static void remove_entity(room_t *room, entity_t *entity)
{
    list_t *list = room->entities;
    list_t *previous = NULL;
    list_t *new_next = NULL;

    while (list) {
        if (list->data == entity)
            break;
        previous = list;
        list = list->next;
    }
    if (!list)
        return;
    if (!previous) {
        room->entities = list->next;
        return;
    }
    if (list->next)
        new_next = list->next;
    free_node(list);
    previous->next = new_next;
}

void on_entity_death(entity_t *entity)
{
    room_t *room;
    int boss;

    room = &get_run()->floors[entity->floor_id].rooms[entity->room_id];
    boss = is_boss(entity->type);
    remove_entity(room, entity);
    if (!room->entities)
        room->finished = 1;
    if (boss)
        return (unlock_next_floor(room));
}
