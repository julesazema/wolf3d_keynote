/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** red_heart_collectible
*/

#include "collectible.h"
#include "../../includes/player.h"

static void heal_player(int amount)
{
    while (get_player()->life + amount > get_player()->max_life)
        amount--;
    get_player()->life += amount;
}

int on_red_heart_pickup(void)
{
    if (get_player()->life >= get_player()->max_life)
        return (0);
    heal_player(2);
    return (1);
}

int on_half_red_heart_pickup(void)
{
    if (get_player()->life >= get_player()->max_life)
        return (0);
    heal_player(1);
    return (1);
}
