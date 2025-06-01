/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bomb_pickups
*/

#include "player.h"

static void add_bombs(int amount)
{
    get_player()->inventory.bombs += amount;
}

int on_bomb_pickup(void)
{
    if (get_player()->inventory.bombs >= 99)
        return (0);
    add_bombs(1);
    return (1);
}

int on_double_bomb_pickup(void)
{
    if (get_player()->inventory.bombs >= 99)
        return (0);
    add_bombs(2);
    return (1);
}
