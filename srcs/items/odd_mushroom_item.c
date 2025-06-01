/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** odd_mushroom_item
*/

#include "../../includes/player.h"

void on_odd_mushroom_pickup(void)
{
    get_player()->max_life += 2;
    get_player()->life += 2;
    if (get_player()->max_life > get_player()->life)
        get_player()->life += 2;
    get_player()->stats.damages += 1.0f;
    get_player()->stats.shoot_range += 0.38;
    get_player()->stats.speed -= 0.2;
}
