/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** run_manager
*/

#include <stdlib.h>

#include "entity.h"
#include "run.h"

static const run_t default_run = {0, 0, {}, 0, 0};

static run_t *local_get_run(void)
{
    static run_t run = default_run;

    return (&run);
}

run_t *get_run(void)
{
    return (local_get_run());
}

void set_run(run_t *run)
{
    *local_get_run() = *run;
}

void generate_run(void)
{
    run_t result = default_run;

    result.slot = 0;
    result.nb_floors = 1;
    generate_floor(&result, 0);
    result.current_floor = 0;
    result.current_room = 0;
    *local_get_run() = result;
}

static void free_list(list_t *list)
{
    list_t *next;

    while (list) {
        next = list->next;
        free_node(list);
        list = next;
    }
}

static void free_room(room_t *room)
{
    free_list(room->entities);
    free_list(room->items);
    free_list(room->collectibles);
    room->entities = NULL;
    room->items = NULL;
    room->collectibles = NULL;
}

static void free_floor(floor_t *floor)
{
    int i;

    i = 0;
    while (i < floor->nb_rooms) {
        free_room(&floor->rooms[i]);
        i++;
    }
}

void unload_run(void)
{
    run_t *run;
    int i;

    run = get_run();
    i = 0;
    while (i < run->nb_floors) {
        free_floor(&run->floors[i]);
        i++;
    }
    *local_get_run() = default_run;
}
