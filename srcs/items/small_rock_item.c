/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** small_rock_item
*/

#include "../../includes/player.h"

void on_small_rock_pickup(void)
{
    get_player()->stats.damages += 1;
    get_player()->stats.attack_speed += 0.2;
    get_player()->stats.speed -= 0.2;
}
