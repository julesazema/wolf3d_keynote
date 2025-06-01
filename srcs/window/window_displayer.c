/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** window_displayer
*/

#include <screen.h>

#include "option.h"
#include "particle.h"
#include "wolf.h"

static void draw(void)
{
    update_particles(0.060f);
    if (get_screen())
        get_screen()->draw_func();
}

void start_loop(void)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(get_window())) {
        while (sfRenderWindow_pollEvent(get_window(), &event))
            on_event(&event);
        sfRenderWindow_clear(get_window(), sfBlack);
        draw();
        sfRenderWindow_display(get_window());
    }
}
