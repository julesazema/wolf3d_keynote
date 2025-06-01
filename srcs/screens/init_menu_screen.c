/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** init_menu_screen
*/

#include "screen.h"
#include "wolf.h"

static void init_sprites_elt(double scale)
{
    scale_sprite("x_button", scale);
    scale_sprite("e_button", scale);
}

void init_sprites(void)
{
    double scale = get_window_width() / 1280.0;

    create_sprite("menu_1", 0, 0, "test_1");
    create_sprite("pointeur", get_window_width() / 2 - (545 * scale),
        get_window_height() / 2 - (350 * scale), "pointeur");
    scale_sprite("menu_1", scale);
    create_sprite("x_button", get_window_width() / 2 - (640 * scale),
        get_window_height() / 2 - (360 * scale), "x_button");
    create_sprite("e_button", get_window_width() / 2 - (640 * scale),
        get_window_height() / 2 - (340 * scale), "e_button");
    init_sprites_elt(scale);
    scale_sprite("pointeur", 1.2f * scale);
}

void load_menu_screen(void)
{
    init_sprites();
    scale_sprite("2_test", 0.2f);
    create_clock("reload", 0.15f);
    play_music("menu_music");
    set_music_volume("menu_music", 0.6f);
    restart_clock("gui_action");
}
