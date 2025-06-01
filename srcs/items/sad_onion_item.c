/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** sad_onion_item
*/

#include "../../includes/player.h"

void on_sad_onion_pickup(void)
{
    get_player()->stats.attack_speed += 0.7;
}
