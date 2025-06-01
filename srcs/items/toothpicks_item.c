/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** toothpicks
*/

#include "../../includes/player.h"

void on_toothpick_pickup(void)
{
    get_player()->stats.attack_speed += 0.7;
    get_player()->stats.tears_speed += 0.16;
}
