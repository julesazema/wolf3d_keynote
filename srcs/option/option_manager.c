/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** option_manager
*/

#include <stdlib.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>

#include "option.h"

static option_part_t **local_get_option(void)
{
    static option_part_t *option = NULL;

    return (&option);
}

void init_option(void)
{
    option_part_t *option;

    option = malloc(sizeof(option_part_t));
    if (!option)
        return;
    option->music = 5;
    option->fov = 60;
    option->fullscreen = 0;
    option->sound = 5;
    option->pipe = sfRectangleShape_create();
    *local_get_option() = option;
}

option_part_t *get_option(void)
{
    return (*local_get_option());
}

void unload_option(void)
{
    sfRectangleShape_destroy(get_option()->pipe);
    free(get_option());
}
