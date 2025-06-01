/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_controls
*/

#include <math.h>

#include "entity.h"
#include "player.h"
#include "tear.h"
#include "wolf.h"

static void jump(void)
{
    player_t *player = get_player();

    if (player->velocity_z != 0.0f)
        return;
    player->velocity_z = 3.0f;
}

static void shoot(void)
{
    launch_tear(get_player());
}

static void place_bomb(void)
{
    player_t *player;

    player = get_player();
    if (player->inventory.bombs <= 0)
        return;
    create_entity(get_current_room(get_run()), E_BOMB, (sfVector3f)
        {player->x, player->y, TILE_SIZE});
    player->inventory.bombs--;
}

void run_player_action(player_action_t action)
{
    if (action == JUMP)
        jump();
    if (action == SHOOT) {
        get_clock("shoot_clock")->time_repeat =
            1 / get_player()->stats.attack_speed;
        if (is_clock_elapsed("shoot_clock"))
            shoot();
    }
    if (action == PLACE_BOMB) {
        if (is_clock_elapsed("bomb_clock"))
            place_bomb();
    }
}
