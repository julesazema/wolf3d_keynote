/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** a_quarter_item
*/

#include "../../includes/player.h"

void on_a_quarter_pickup(void)
{
    get_player()->inventory.coins += 25;
}
