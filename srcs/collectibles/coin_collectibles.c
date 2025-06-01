/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** coin_collectibles
*/

#include "player.h"

static void add_coins(int amount)
{
    while (get_player()->inventory.coins + amount > 99)
        amount--;
    get_player()->inventory.coins += amount;
}

int on_penny_pickup(void)
{
    if (get_player()->inventory.coins >= 99)
        return (0);
    add_coins(1);
    return (1);
}

int on_nickel_pickup(void)
{
    if (get_player()->inventory.coins >= 99)
        return (0);
    add_coins(5);
    return (1);
}

int on_dime_pickup(void)
{
    if (get_player()->inventory.coins >= 99)
        return (0);
    add_coins(10);
    return (1);
}
