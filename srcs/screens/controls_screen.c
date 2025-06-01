/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** controls_screen
*/

#include "option.h"
#include "wolf.h"
#include "screen.h"

static int *local_get_position(void)
{
    static int position = 0;

    return (&position);
}

static int *local_get_change(void)
{
    static int change = 0;

    return (&change);
}

static void load_controls_title(double scale)
{
    create_menu_text("jump", get_control()[0]->name, 60 * scale);
    center_text("jump", get_window_width() / 2 + (160 * scale), 0 * 80 * scale
        + (120 * scale));
    create_menu_text("z", get_control()[1]->name, 60 * scale);
    center_text("z", get_window_width() / 2 + (160 * scale), 1 * 80 * scale
        + (120 * scale));
    create_menu_text("s", get_control()[2]->name, 60 * scale);
    center_text("s", get_window_width() / 2 + (160 * scale), 2 * 80 * scale
        + (120 * scale));
    create_menu_text("d", get_control()[3]->name, 60 * scale);
    center_text("d", get_window_width() / 2 + (160 * scale), 3 * 80 * scale
        + (120 * scale));
    create_menu_text("q", get_control()[4]->name, 60 * scale);
    center_text("q", get_window_width() / 2 + (160 * scale), 4 * 80 * scale
        + (120 * scale));
    create_menu_text("c", get_control()[5]->name, 60 * scale);
    center_text("c", get_window_width() / 2 + (160 * scale), 5 * 80 * scale
        + (120 * scale));
    move_text("change", 100, 100);
}

static void load_controls_resize(void)
{
    double scale = get_window_width() / 1280.0;

    for (int i = 0; get_control()[i]; i++) {
        create_menu_text(get_control()[i]->description, get_control()
            [i]->description, 60 * scale);
        move_text(get_control()[i]->description, get_window_width() / 2 -
            (260 * scale), i * 80 * scale + (120 * scale));
    }
    rescale_sprite("menu", scale);
    load_controls_title(scale);
    load_resource("arrow", "assets/backgrouds/pointeur.png",
        TEXTURE);
    create_sprite("arrow", get_window_width() / 2 - (530 * scale),
        get_window_height() / 2 - (320 * scale) + ((*local_get_position() * 80
            ) - 80) * scale, "arrow");
    rescale_sprite("arrow", scale);
}

void load_controls_screen(void)
{
    load_resource("menu", "assets/backgrouds/menu_nothing.png",
        TEXTURE);
    load_resource("isaac_font", "assets/font/Isaac.ttf", FONT);
    create_sprite("menu", 0, 0, "menu");
    restart_clock("gui_action");
    create_clock("bloque", 0.2f);
    restart_clock("bloque");
    load_controls_resize();
    *local_get_position() = 1;
    *local_get_change() = 0;
}

static void set_move_controls(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && is_clock_elapsed("bloque") &&
        *local_get_position() > 1) {
        *local_get_position() -= 1;
        play_sound("splatter01");
        }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && is_clock_elapsed("bloque") &&
        *local_get_position() < 6) {
        *local_get_position() += 1;
        play_sound("splatter01");
        }
}

void draw_controls_screen(void)
{
    load_controls_resize();
    draw_sprite("menu");
    draw_text("jump");
    draw_text("z");
    draw_text("s");
    draw_text("d");
    draw_text("q");
    draw_text("c");
    for (int i = 0; get_control()[i]; i++) {
        draw_text(get_control()[i]->description);
    }
    draw_sprite("arrow");
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && is_clock_elapsed("gui_action"))
        set_screen(S_OPTIONS);
    set_move_controls();
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && is_clock_elapsed("bloque"))
        *local_get_change() = 1;
}

static void center_all_text(void)
{
    double scale = get_window_width() / 1280.0;

    center_text("jump", 800, 0 * 80 * scale + (120 * scale));
    center_text("z", 800, 1 * 80 * scale + (120 * scale));
    center_text("s", 800, 2 * 80 * scale + (120 * scale));
    center_text("d", 800, 3 * 80 * scale + (120 * scale));
    center_text("q", 800, 4 * 80 * scale + (120 * scale));
    center_text("c", 800, 5 * 80 * scale + (120 * scale));
}

void on_key_pressed_controlscreen(sfEvent event)
{
    if (*local_get_change() == 1) {
        get_control()[*local_get_position() - 1]->code = event.key.code;
        get_control()[*local_get_position() - 1]->name = get_name_control
        (event.key.code);
        if (*local_get_position() == 1)
            change_text("jump", get_control()[0]->name);
        if (*local_get_position() == 2)
            change_text("z", get_control()[1]->name);
        if (*local_get_position() == 3)
            change_text("s", get_control()[2]->name);
        if (*local_get_position() == 4)
            change_text("d", get_control()[3]->name);
        if (*local_get_position() == 5)
            change_text("q", get_control()[4]->name);
        if (*local_get_position() == 6)
            change_text("c", get_control()[5]->name);
        center_all_text();
        *local_get_change() = 0;
    }
}

void unload_controls_screen(void)
{
}
