/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** dollar_item
*/

#include <stdio.h>
#include "../../includes/player.h"

void on_dollar_pickup(void)
{
    get_player()->inventory.coins = 99;
}
