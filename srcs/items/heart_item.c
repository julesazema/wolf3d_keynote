/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** heart_item
*/

#include "player.h"

void on_heart_pickup(void)
{
    get_player()->max_life += 2;
    get_player()->life += 4;
    if (get_player()->max_life > 24)
        get_player()->max_life = 24;
    if (get_player()->life > get_player()->max_life)
        get_player()->life = get_player()->max_life;
}
