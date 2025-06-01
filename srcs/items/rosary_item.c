/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** rosary_item
*/

#include "../../includes/player.h"

void on_rosary_pickup(void)
{
    get_player()->blue_hearth += 3;
    get_player()->stats.attack_speed += 5;
}
