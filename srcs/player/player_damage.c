/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_damage
*/

#include "player.h"
#include "run.h"
#include "screen.h"

void player_death(player_t *player)
{
    (void)player;
    set_screen(S_INTRO);
}

void damage_player(player_t *player, int amount)
{
    while (amount > 0 && player->blue_hearth > 0) {
        player->blue_hearth--;
        amount--;
    }
    while (amount > 0 && player->life > 0) {
        player->life--;
        amount--;
    }
    if (player->life <= 0 && player->blue_hearth == 0)
        player_death(player);
}
