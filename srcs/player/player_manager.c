/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_manager
*/

#include <stdlib.h>
#include <wolf.h>

#include "player.h"
#include "run.h"

static const player_t default_player = {
    {NULL, 0, 0, 0},
    {1, 2.73, 3.5, 6.5, 1, 0, 0, 0},
    0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 0
};

static player_t *local_get_player(void)
{
    static player_t player = default_player;

    return (&player);
}

void init_player(void)
{
    player_t result = default_player;

    result.yaw = 1.625;
    *local_get_player() = result;
}

player_t *get_player(void)
{
    return (local_get_player());
}

void unload_player(void)
{
    *local_get_player() = default_player;
}
