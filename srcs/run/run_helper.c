/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** run_helper
*/

#include <stddef.h>
#include "run.h"

room_t *get_room(floor_t *floor, int x, int y)
{
    int i;

    i = 0;
    while (i < floor->nb_rooms) {
        if (floor->rooms[i].floor_x == x &&
            floor->rooms[i].floor_y == y)
            return (&floor->rooms[i]);
        i++;
    }
    return (NULL);
}

floor_t *get_current_floor(run_t *run)
{
    if (run->nb_floors <= run->current_floor)
        return (NULL);
    return (&run->floors[run->current_floor]);
}

room_t *get_current_room(run_t *run)
{
    return (&get_current_floor(run)->rooms[run->current_room]);
}

int count_links(floor_t *floor, int x, int y)
{
    int i;

    i = 0;
    i += get_room(floor, x, y + 1) != NULL;
    i += get_room(floor, x, y - 1) != NULL;
    i += get_room(floor, x + 1, y) != NULL;
    i += get_room(floor, x - 1, y) != NULL;
    return (i);
}

void generate_room_matrix(room_t *dest)
{
    int i = 0;
    int j;

    while (i < dest->height) {
        j = 0;
        while (j < dest->width) {
            dest->matrix[i][j] = 0;
            j++;
        }
        i++;
    }
}
