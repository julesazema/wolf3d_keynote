/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_shoot
*/

#include "option.h"
#include "tear.h"

void handle_player_shoot(void)
{
    if (!is_control_pressed(K_SHOOT))
        return;
    run_player_action(SHOOT);
}

void handle_player_bomb(void)
{
    if (!is_control_pressed(K_PLACEBOMB))
        return;
    run_player_action(PLACE_BOMB);
}
