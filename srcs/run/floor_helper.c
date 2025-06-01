/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** floor_helper
*/

#include <stddef.h>

#include "run.h"

room_t *get_unlinked_room(floor_t *floor)
{
    int i;

    i = 0;
    while (i < floor->nb_rooms) {
        if (count_links(floor,
            floor->rooms[i].floor_x, floor->rooms[i].floor_y) == 1 &&
            floor->rooms[i].type == CLASSIC_ROOM)
            return (&floor->rooms[i]);
        i++;
    }
    return (NULL);
}
