/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** mouse_utils
*/

#include "wolf.h"

static int *local_get_mouse_position(void)
{
    static int infos[2] = {0, 0};

    return (infos);
}

static int *local_get_mouse_current_position(void)
{
    static int infos[2] = {0, 0};

    return (infos);
}

int is_mouse_inrange(sfFloatRect box, int mouse_x, int mouse_y)
{
    if (mouse_x < box.left || mouse_x > box.left + box.width)
        return (0);
    if (mouse_y < box.top || mouse_y > box.top + box.height)
        return (0);
    return (1);
}

void update_mouse_position(int mouse_x, int mouse_y)
{
    local_get_mouse_current_position()[0] = local_get_mouse_position()[0];
    local_get_mouse_current_position()[1] = local_get_mouse_position()[1];
    local_get_mouse_position()[0] = mouse_x;
    local_get_mouse_position()[1] = mouse_y;
}
