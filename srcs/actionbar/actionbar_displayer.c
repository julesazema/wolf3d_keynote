/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** actionbar_displayer
*/

#include "actionbar.h"
#include "wolf.h"

static void launch_bar(actionbar_t *actionbar)
{
    if (!get_clock("action_bar"))
        create_clock("action_bar", 0.02f);
    create_sprite("splatter", 0, 50, "splatter_texture");
    rescale_sprite("splatter", 1280.0f / get_window_width());
    restart_clock("action_bar");
    create_text("action_bar", "", "font");
    outline_text("action_bar", 5, sfBlack);
    scale_text("action_bar", 64);
    create_text("action_bar_sub", "", "subfont");
    outline_text("action_bar_sub", 5, sfBlack);
    scale_text("action_bar_sub", 32);
    change_text("action_bar", actionbar->content);
    change_text("action_bar_sub", actionbar->subtitle);
    actionbar->launched = 1;
}

static void draw_contents(double x_offset)
{
    center_text("action_bar",
        get_window_width() / 2 - (x_offset * 3), 100);
    center_text("action_bar_sub",
        get_window_width() / 2 - (x_offset * 3), 175);
    center_sprite("splatter",
        get_window_width() / 2 + (x_offset * 3), 50);
    draw_sprite("splatter");
    draw_text("action_bar");
    draw_text("action_bar_sub");
}

void display_actionbars(void)
{
    actionbar_t *actionbar;
    double x_offset = 0;

    actionbar = get_top_action();
    if (!actionbar)
        return;
    if (!actionbar->launched)
        launch_bar(actionbar);
    if (actionbar->displayed_time >= actionbar->max_time)
        return (remove_actionbar(actionbar));
    if (actionbar->displayed_time < 0.05)
        x_offset = (0.05f - actionbar->displayed_time) * 1600;
    if (actionbar->displayed_time > actionbar->max_time - 0.05)
        x_offset = (0.05f - (actionbar->max_time - actionbar->displayed_time))
            * -1600;
    draw_contents(x_offset);
    if (is_clock_elapsed("action_bar"))
        actionbar->displayed_time += 0.02f;
}
