/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** cricket_head_item
*/

#include "../../includes/player.h"

void on_crickets_head_pickup(void)
{
    get_player()->stats.damages += 0.5;
    get_player()->stats.damages *= 1.5;
}
