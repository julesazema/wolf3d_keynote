/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** window_manager
*/

#include "wolf.h"

static sfRenderWindow **local_get_window(void)
{
    static sfRenderWindow *window = NULL;

    return (&window);
}

void init_window(int width, int height, char *title, int full_screen)
{
    sfRenderWindow *window;
    sfUint32 style;
    size_t count;

    if (*local_get_window() != NULL)
        destroy_window();
    style = sfClose;
    if (full_screen)
        style |= sfFullscreen;
    sfVideoMode_getFullscreenModes(&count);
    window = sfRenderWindow_create(full_screen ?
        sfVideoMode_getFullscreenModes(&count)[0] :
        (sfVideoMode) {width, height, 60}, title, style, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    *local_get_window() = window;
}

sfRenderWindow *get_window(void)
{
    return (*local_get_window());
}

void destroy_window(void)
{
    if (*local_get_window() == NULL)
        return;
    sfRenderWindow_destroy(*local_get_window());
    *local_get_window() = NULL;
}
