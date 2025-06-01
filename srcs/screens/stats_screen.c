/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** stats_screen
*/

#include "wolf.h"
#include "screen.h"
#include "stats.h"

void load_stats_screen(void)
{
    load_resource("isaac_font", "assets/font/Isaac.ttf", FONT);
    load_resource("menu", "assets/backgrouds/menu_nothing.png", TEXTURE);
    create_clock("bloque", 0.2f);
    create_clock("seconde", 1.0f);
    create_sprite("menu", 0, 0, "menu");
    create_menu_text("time", "time", 100);
    create_menu_text("dead", "deads", 100);
    create_menu_text("kill", "kills", 100);
    create_menu_text("nb_game", "run", 100);
    create_menu_text("time_value", get_stat(TIME), 100);
    create_menu_text("dead_value", get_stat(DEAD), 100);
    create_menu_text("kill_value", get_stat(KILL), 100);
    create_menu_text("nb_game_value", get_stat(NB_GAME), 100);
}

static void draw_stats_value(int position, int i, int x, char *text)
{
    if (position - i >= 120 && position + i <= 840)
        center_text(text, x, position - i);
    else
        center_text(text, 1000, 1000);
}

static void set_text_position(int i)
{
    draw_stats_value(120, i, 420, "time");
    draw_stats_value(120, i, 840, "time_value");
    draw_stats_value(220, i, 440, "dead");
    draw_stats_value(220, i, 840, "dead_value");
    draw_stats_value(320, i, 420, "kill");
    draw_stats_value(320, i, 840, "kill_value");
    draw_stats_value(420, i, 400, "nb_game");
    draw_stats_value(420, i, 840, "nb_game_value");
}

static void draw_stats_texts(void)
{
    draw_text("time");
    draw_text("time_value");
    draw_text("dead");
    draw_text("dead_value");
    draw_text("kill");
    draw_text("kill_value");
    draw_text("nb_game");
    draw_text("nb_game_value");
}

void draw_stats_screen(void)
{
    static int i = 0;

    draw_sprite("menu");
    if (is_clock_elapsed("seconde"))
        add_stats_change_text(TIME, "time_value");
    if (sfKeyboard_isKeyPressed(sfKeyUp) &&
        is_clock_elapsed("bloque") && i < 300) {
        add_stats_change_text(TIME, "time_value");
        i += 100;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) &&
        is_clock_elapsed("bloque") && i > 0)
        i -= 100;
    set_text_position(i);
    draw_stats_texts();
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        set_screen(S_MENU);
}

void unload_stats_screen(void)
{
    hide_text("time");
    hide_text("dead");
    hide_text("time_value");
    hide_text("dead_value");
    hide_text("kill");
    hide_text("kill_value");
    hide_text("nb_game");
    hide_text("nb_game_value");
}
