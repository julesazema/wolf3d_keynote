/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** synthoil_item
*/

#include "../../includes/player.h"

void on_sinthoil_pickup(void)
{
    get_player()->stats.damages += 3;
    get_player()->stats.shoot_range += 1.5;
}
