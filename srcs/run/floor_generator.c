/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** floor_generator
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "collectible.h"
#include "entity.h"
#include "item.h"
#include "player.h"
#include "run.h"
#include "wolf.h"

static int is_location_occupied(floor_t *floor, int x, int y, int size)
{
    int occupied;
    int i;

    occupied = 0;
    i = 0;
    while (i < size) {
        if (floor->rooms[i].floor_x == x && floor->rooms[i].floor_y == y) {
            occupied = 1;
            break;
        }
        i++;
    }
    return (occupied);
}

static void apply_dir(int dir, int new_loc[2])
{
    if (dir == 0) {
        new_loc[1]--;
        return;
    }
    if (dir == 1) {
        new_loc[0]++;
        return;
    }
    if (dir == 2) {
        new_loc[1]++;
        return;
    }
    if (dir == 3)
        new_loc[0]--;
}

static void generate_rooms(floor_t *floor)
{
    room_t *parent;
    int parent_index;
    int new_loc[2];
    int i = 1;

    floor->rooms[0] = generate_room_content(CLASSIC_ROOM, 0, 0, 0);
    floor->rooms[0].floor_id = floor->floor_id;
    while (i < floor->nb_rooms) {
        parent_index = get_random(i);
        parent = &floor->rooms[parent_index];
        new_loc[0] = parent->floor_x;
        new_loc[1] = parent->floor_y;
        apply_dir(get_random(4), new_loc);
        if (is_location_occupied(floor, new_loc[0], new_loc[1], i))
            continue;
        floor->rooms[i] =
            generate_room_content(CLASSIC_ROOM, i, new_loc[0], new_loc[1]);
        floor->rooms[i].floor_id = floor->floor_id;
        i++;
    }
}

static void setup_special_rooms(floor_t *floor)
{
    room_t *boss;
    room_t *shop;
    room_t *item;

    boss = create_unlinked_room(floor, BOSS_ROOM);
    shop = create_unlinked_room(floor, SHOP);
    item = create_unlinked_room(floor, ITEM_ROOM);
    if (!boss || !shop || !item) {
        generate_rooms(floor);
        setup_special_rooms(floor);
        return;
    }
    if (get_random(3) == 0)
        create_unlinked_room(floor, SACRIFICE_ROOM);
    shop->collectibles = generate_room_collectibles();
    item->items = generate_room_items();
}

static void setup_entities(floor_t *floor)
{
    int i;

    i = 0;
    while (i < floor->nb_rooms) {
        generate_room_entities(&floor->rooms[i]);
        i++;
    }
}

void generate_floor(run_t *run, int floor_index)
{
    if (floor_index > 1)
        run->floors[floor_index].nb_rooms = 0;
    run->floors[floor_index].type = THE_BASEMENT;
    run->floors[floor_index].nb_rooms = 5 + get_random(4);
    run->floors[floor_index].floor_id = floor_index;
    generate_rooms(&run->floors[floor_index]);
    setup_special_rooms(&run->floors[floor_index]);
    setup_entities(&run->floors[floor_index]);
    run->floors[floor_index].rooms[0].finished = 1;
    run->floors[floor_index].rooms[0].visited = 1;
}
