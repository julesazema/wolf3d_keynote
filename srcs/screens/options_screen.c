/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** options
*/

#include <stdio.h>
#include <bits/getopt_core.h>

#include "wolf.h"
#include "screen.h"
#include "option.h"
#include "run.h"

static int *local_get_position(void)
{
    static int position = 0;

    return (&position);
}

static void load_options_title(double scale)
{
    create_menu_text("control", "CONTROLS", 80 * scale);
    move_text("control", get_window_width() / 2 - (270 * scale),
        get_window_height() / 2 - (260 * scale));
    create_menu_text("music", "MUSICS", 80 * scale);
    move_text("music", get_window_width() / 2 - (270 * scale),
        get_window_height() / 2 - (160 * scale));
    create_menu_text("sound", "SOUNDS", 80 * scale);
    move_text("sound", get_window_width() / 2 - (270 * scale),
        get_window_height() / 2 - (60 * scale));
    create_menu_text("fov", "FOV", 80 * scale);
    move_text("fov", get_window_width() / 2 - (270 * scale),
        get_window_height() / 2 + (40 * scale));
    create_menu_text("fullscreen", "FULLSCREEN", 80 * scale);
    move_text("fullscreen", get_window_width() / 2 - (270 * scale),
        get_window_height() / 2 + (140 * scale));
}

static void load_options_resize(void)
{
    double scale = get_window_width() / 1280.0;

    create_sprite("menu", get_window_width() / 2 - (640 * scale),
        get_window_height() / 2 - (360 * scale), "menu");
    rescale_sprite("menu", scale);
    load_options_title(scale);
    create_menu_text("on", "ON", 80 * scale);
    create_menu_text("off", "OFF", 80 * scale);
    create_menu_text("fov_value", "0", 80 * scale);
    center_text("fov_value", get_window_width() / 2 + (110 * scale),
        get_window_height() / 2 + (40 * scale));
    load_resource("arrow", "assets/backgrouds/pointeur.png",
        TEXTURE);
    create_sprite("arrow", get_window_width() / 2 - (530 * scale),
        (get_window_height() / 2 - (330 * scale)) + ((*local_get_position()
            * 100) - 100) * scale, "arrow");
    rescale_sprite("arrow", scale);
}

void load_options_screen(void)
{
    stop_music("menu_music");
    restart_clock("gui_action");
    load_resource("isaac_font", "assets/font/Isaac.ttf", FONT);
    load_resource("menu", "assets/backgrouds/menu_nothing.png", TEXTURE);
    create_clock("bloque", 0.2f);
    load_options_resize();
    *local_get_position() = 1;
}

static void change_value(int *value, int delta)
{
    *value += delta;
    play_sound("splatter02");
}

static void handle_bars(sfKeyCode key)
{
    if (key == sfKeyRight) {
        if (*local_get_position() == 2 && get_option()->music < 10)
            change_value(&get_option()->music, 1);
        if (*local_get_position() == 3 && get_option()->sound < 10)
            change_value(&get_option()->sound, 1);
        if (*local_get_position() == 4 && get_option()->fov < 120)
            change_value(&get_option()->fov, 5);
    }
    if (key == sfKeyLeft) {
        if (*local_get_position() == 2 && get_option()->music > 0)
            change_value(&get_option()->music, -1);
        if (*local_get_position() == 3 && get_option()->sound > 0)
            change_value(&get_option()->sound, -1);
        if (*local_get_position() == 4 && get_option()->fov > 5)
            change_value(&get_option()->fov, -5);
    }
}

static void set_key_options(void)
{
    if (is_control_pressed(K_ENTER) && is_clock_elapsed("gui_action")) {
        if (*local_get_position() == 5) {
            set_fullscreen();
            play_sound("splatter02");
        }
        if (*local_get_position() == 1) {
            set_screen(S_CONTROLS);
            play_sound("splatter02");
        }
    }
    if ((sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyLeft)) && is_clock_elapsed("bloque")) {
        handle_bars(sfKeyboard_isKeyPressed(sfKeyRight) ?
            sfKeyRight : sfKeyLeft);
    }
}

void draw_options_screen(void)
{
    load_options_resize();
    if (is_control_pressed(K_UP) && is_clock_elapsed("bloque") &&
        *local_get_position() > 1) {
        *local_get_position() -= 1;
        play_sound("splatter01");
    }
    if (is_control_pressed(K_DOWN) && is_clock_elapsed("bloque") &&
        *local_get_position() < 5) {
        *local_get_position() += 1;
        play_sound("splatter01");
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && is_clock_elapsed("gui_action"))
        set_screen(S_MENU);
    set_key_options();
    draw_sprite("menu");
    draw_options_texts();
    draw_sprite("arrow");
}

void unload_options_screen(void)
{
}
