/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** content_helper
*/

#include <stdio.h>

#include "entity.h"
#include "player.h"
#include "run.h"

void generate_rocks(room_t *room)
{
    int i;

    i = 0;
    while (i < 3) {
        create_entity(room, E_ROCK, (sfVector3f) {
            (float)get_random((room->width) * TILE_SIZE),
            (float)get_random((room->height) * TILE_SIZE),
            0.15f * TILE_SIZE
        });
        i++;
    }
}

void generate_fires(room_t *room)
{
    int i;

    i = 0;
    while (i < 3) {
        create_entity(room, E_FIRE, (sfVector3f) {
            (float)(i + 1) * TILE_SIZE,
            (float)room->width / 2 * TILE_SIZE,
            0.35f * TILE_SIZE
        });
        i++;
    }
}

static entity_type_t get_random_type(void)
{
    int random;

    random = get_random(4);
    if (random == 0)
        return E_CACA;
    if (random == 1)
        return E_FATTY;
    if (random == 2)
        return E_FLY;
    if (random == 3)
        return E_RED_FLY;
    return (E_EMBRYO);
}

void generate_monsters(room_t *room)
{
    int i;

    i = 0;
    while (i < 3) {
        create_entity(room, get_random_type(), (sfVector3f) {
            (float)(i + 1) * TILE_SIZE,
            (float)room->width / 2 * TILE_SIZE,
            0.15f * TILE_SIZE
        });
        i++;
    }
}

static entity_type_t get_random_boss_type(void)
{
    int random;

    random = get_random(3);
    if (random == 0)
        return E_LOKI;
    return (E_KING_FLY);
}

void generate_room_entities(room_t *dest)
{
    if (dest->id == 0)
        return;
    if (dest->type == CLASSIC_ROOM) {
        generate_rocks(dest);
        generate_fires(dest);
        generate_monsters(dest);
    }
    if (dest->type == BOSS_ROOM)
        create_entity(dest, get_random_boss_type(), (sfVector3f)
            {(float) dest->width / 2 * TILE_SIZE,
                (float) dest->height / 2 * TILE_SIZE, 0.6f * TILE_SIZE});
}
