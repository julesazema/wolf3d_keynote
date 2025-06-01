/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** number_one
*/

#include "../../includes/player.h"

void on_number_one_pickup(void)
{
    get_player()->stats.attack_speed += 1.5;
    get_player()->stats.shoot_range -= 2.5;
}
