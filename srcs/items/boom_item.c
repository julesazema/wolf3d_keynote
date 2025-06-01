/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** boom_item
*/

#include "../../includes/player.h"

void on_boom_pickup(void)
{
    get_player()->inventory.bombs += 10;
}
