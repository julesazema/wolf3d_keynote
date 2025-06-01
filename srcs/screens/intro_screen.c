/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** intro_screen
*/

#include <wolf.h>

#include "option.h"
#include "screen.h"

void load_intro_screen(void)
{
    double scale = get_window_width() / 1280.0;

    load_resource("background_menu", "assets/backgrouds/start_menu_2.png",
        TEXTURE);
    load_resource("press_button", "assets/backgrouds/bouton_press.png",
        TEXTURE);
    create_sprite("backgroud_menu", 0, 0, "background_menu");
    create_sprite("button_press", get_window_width() / 2 - (300 * scale),
        get_window_height() / 2 + (80 * scale), "press_button");
    scale_sprite("backgroud_menu", scale);
    scale_sprite("button_press", scale);
    create_clock("gui_action", 0.2f);
    restart_clock("gui_action");
    set_music_volume("menu_music", .85f);
    if (get_music_status("menu_music") != sfPlaying)
        set_music_playing_offset("menu_music", 0.0f);
    play_music("menu_music");
}

void draw_intro_screen(void)
{
    static int i = 0;
    double scale = get_window_width() / 1280.0;

    place_sprite("button_press", get_window_width() / 2 - (300 * scale),
        get_window_height() / 2 + (80 * scale));
    rescale_sprite("backgroud_menu", scale);
    rescale_sprite("button_press", scale);
    draw_sprite("backgroud_menu");
    if (i < 60)
        draw_sprite("button_press");
    if (i > 80)
        i = 0;
    i++;
    if (is_control_pressed(K_ENTER) && is_clock_elapsed("gui_action"))
        set_screen(S_MENU);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && is_clock_elapsed("gui_action"))
        sfRenderWindow_close(get_window());
}

void unload_intro_screen(void)
{
    stop_music("menu_music");
}
