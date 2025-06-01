/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_stats
*/

#include <stdio.h>

#include "player.h"
#include "wolf.h"

static void return_stats(char *name, double i)
{
    char result[6];
    int number = (int) i;

    if (number / 10 == 0)
        result[0] = ' ';
    else {
        result[0] = (number / 10) + '0';
    }
    result[1] = number + '0';
    result[2] = '.';
    result[3] = (int) (i * 10) % 10 + '0';
    result[4] = (int) (i * 100) % 10 + '0';
    result[5] = '\0';
    change_text(name, result);
}

void draw_player_stats(void)
{
    return_stats("shoot_speed", get_player()->stats.attack_speed);
    return_stats("speed", get_player()->stats.speed);
    return_stats("dammage", get_player()->stats.damages);
    return_stats("range", get_player()->stats.shoot_range);
    return_stats("ball_speed", get_player()->stats.tears_speed);
    return_stats("luck", get_player()->stats.chance);
    draw_sprite("shoot_speed");
    draw_sprite("speed");
    draw_sprite("dammage");
    draw_sprite("range");
    draw_sprite("ball_speed");
    draw_sprite("luck");
    draw_text("shoot_speed");
    draw_text("speed");
    draw_text("dammage");
    draw_text("range");
    draw_text("ball_speed");
    draw_text("luck");
}
