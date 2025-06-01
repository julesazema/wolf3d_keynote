/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** init_options_screen
*/

#include "option.h"

static void set_rect(int i, int position)
{
    double scale = get_window_width() / 1280.0;

    for (int j = 1; j <= 10; j++) {
        if (j <= i)
            sfRectangleShape_setFillColor(get_option()->pipe,
                sfColor_fromRGB(83, 60, 8));
        else
            sfRectangleShape_setFillColor(get_option()->pipe, sfBlack);
        sfRectangleShape_setSize(get_option()->pipe, (sfVector2f){10 *
            scale, 40 * scale});
        sfRectangleShape_setPosition(get_option()->pipe, (sfVector2f){
            get_window_width() / 2 + (40 * get_window_width() / 1280.0) +
            (j * (15 * scale)), position + 35});
        sfRenderWindow_drawRectangleShape(get_window(), get_option()->pipe,
            NULL);
    }
}

static void draw_end_options(void)
{
    char tmp[16];

    set_rect(get_option()->music, get_window_height() / 2 - (160 *
        get_window_width() / 1280.0));
    set_rect(get_option()->sound, get_window_height() / 2 - (60 *
        get_window_width() / 1280.0));
    change_text("fov_value", ft_itoad(get_option()->fov, tmp, 16));
    draw_text("fov_value");
}

void draw_options_texts(void)
{
    draw_text("control");
    draw_text("music");
    draw_text("sound");
    draw_text("fov");
    draw_text("fullscreen");
    if (get_option()->fullscreen) {
        center_text("on", get_window_width() / 2 + (220 * get_window_width()
            / 1280.0), get_window_height() / 2 + (140 * get_window_width() /
                1280.0));
        draw_text("on");
    } else {
        center_text("off", get_window_width() / 2 + (220 * get_window_width()
            / 1280.0), get_window_height() / 2 + (140 * get_window_width() /
                1280.0));
        draw_text("off");
    }
    draw_end_options();
}
