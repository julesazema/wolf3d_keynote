/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** pyromania_item
*/

#include "../../includes/player.h"

void on_pyromania_pickup(void)
{
    get_player()->inventory.bombs += 5;
}
