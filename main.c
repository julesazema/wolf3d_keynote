/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** main
*/

#include <player.h>
#include <screen.h>
#include "minimap.h"
#include "wolf.h"
#include "raycaster.h"
#include "option.h"
#include "particle.h"

void on_enable(void)
{
    load_resources();
    init_option();
    init_player();
    init_window(1280, 720, "wolf3d", 0);
    init_ray();
    set_screen(S_INTRO);
    init_minimap();
    init_control();
}

void on_disable(void)
{
    destroy_window();
    unload_run();
    unload_screen();
    unload_player();
    unload_resources();
    unload_buttons();
    unload_texts();
    unload_clocks();
    unload_ray();
    unload_minimap();
    unload_option();
    unload_control();
}

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;
    if (!is_graphical(envp)) {
        ft_putstr_fd(2, "wolf3d: Error: Not in a graphical environment.\n");
        return (84);
    }
    on_enable();
    start_loop();
    on_disable();
    return (0);
}
