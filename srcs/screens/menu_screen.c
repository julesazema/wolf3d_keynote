/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** menu_screen
*/

#include "screen.h"
#include "list.h"
#include "wolf.h"
#include <malloc.h>
#include <stdlib.h>

#include "option.h"
#include "player.h"
#include "run.h"

static void handle_arrows(int *item_index)
{
    if ((is_control_pressed(K_DOWN) || is_control_pressed(K_UP)) &&
            !is_clock_elapsed("reload"))
        return;
    if (is_control_pressed(K_DOWN) && *item_index < 5) {
        play_sound("splatter01");
        *item_index += 1;
    }
    if (is_control_pressed(K_UP) && *item_index > 0) {
        play_sound("splatter01");
        *item_index -= 1;
    }
}

static void launch_new_run(void)
{
    init_player();
    launch_run();
    set_screen(S_GAME);
}

void continue_run(void)
{
    init_player();
    if (load_run()) {
        set_screen(S_GAME);
        launch_room(get_run()->current_room);
    } else
        ft_putstr_fd(2, "Corrupted save.\n");
}

static void make_menu_action(int i)
{
    if (is_control_pressed(K_ENTER) && is_clock_elapsed("gui_action")) {
        if (i == 0)
            launch_new_run();
        if (i == 1)
            set_screen(S_MAPMAKER);
        if (i == 4)
            set_screen(S_STATS);
        if (i == 5)
            set_screen(S_OPTIONS);
        play_sound("splatter02");
    }
}

static void centre_pointeur(int i)
{
    double scale = get_window_width() / 1280.0;

    if (i == 1)
        move_sprite("pointeur", -30 * scale, 75 * scale);
    if (i == 2)
        move_sprite("pointeur", 20 * scale, 155 * scale);
    if (i == 3)
        move_sprite("pointeur", -5 * scale, 235 * scale);
    if (i == 4)
        move_sprite("pointeur", 90 * scale, 315 * scale);
    if (i == 5)
        move_sprite("pointeur", 60 * scale, 390 * scale);
}

void draw_menu_screen(void)
{
    static int i = 0;

    init_sprites();
    centre_pointeur(i);
    draw_sprite("menu_1");
    draw_sprite("pointeur");
    handle_arrows(&i);
    make_menu_action(i);
    draw_sprite(get_input_type() == I_CONTROLLER ? "x_button" : "e_button");
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && is_clock_elapsed("gui_action"))
        set_screen(S_INTRO);
}

void unload_menu_screen(void)
{
}
