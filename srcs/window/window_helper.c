/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** window_helper
*/

#include "wolf.h"

unsigned int get_window_width(void)
{
    return (sfRenderWindow_getSize(get_window()).x);
}

unsigned int get_window_height(void)
{
    return (sfRenderWindow_getSize(get_window()).y);
}
