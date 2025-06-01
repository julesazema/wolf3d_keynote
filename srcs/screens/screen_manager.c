/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** screen_manager
*/

#include <stdlib.h>
#include "screen.h"

static const screen_t screens[] = {
    {S_MENU, &load_menu_screen, &draw_menu_screen, &unload_menu_screen},
    {S_INTRO, &load_intro_screen, &draw_intro_screen, &unload_intro_screen},
    {S_GAME, &load_game_screen, &draw_game_screen, &unload_game_screen},
    {S_STATS, &load_stats_screen, &draw_stats_screen, &unload_stats_screen},
    {S_OPTIONS, &load_options_screen, &draw_options_screen,
        &unload_options_screen},
    {S_CONTROLS, &load_controls_screen, &draw_controls_screen,
        &unload_controls_screen},
    {S_MAPMAKER, &load_mapmaker_screen, &draw_mapmaker_screen,
        &unload_mapmaker_screen},
    {S_PAUSED, &load_paused_screen, &draw_paused_screen,
        &unload_paused_screen},
    {0, 0, 0, 0}
};

screen_t **local_get_screen(void)
{
    static screen_t *screen = NULL;

    return (&screen);
}

void set_screen(screen_type_t type)
{
    screen_t *screen;
    int i;

    screen = NULL;
    i = 0;
    while (screens[i].type) {
        if (screens[i].type == type)
            screen = (screen_t *) &screens[i];
        i++;
    }
    if (!screen)
        return;
    unload_screen();
    *local_get_screen() = screen;
    screen->load_func();
}

screen_t *get_screen(void)
{
    return (*local_get_screen());
}

void unload_screen(void)
{
    if (!get_screen())
        return;
    get_screen()->unload_func();
    *local_get_screen() = NULL;
}
