/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** cat_o_nine_tails_item
*/

#include "../../includes/player.h"

void on_cat_o_nine_tails_pickup(void)
{
    get_player()->stats.damages += 1.0;
    get_player()->stats.attack_speed += 0.23;
}
