/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** polyphemus_item
*/

#include "../../includes/player.h"

void on_polyphemus_pickup(void)
{
    get_player()->stats.damages = (get_player()->stats.damages + 4) * 2;
    get_player()->stats.attack_speed *= 1.5;
}
