/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** paused_screen
*/

#include "collectible.h"
#include "raycaster.h"
#include "screen.h"
#include "option.h"
#include "run.h"
#include "wolf.h"

static void load_paused_stats(void)
{
    load_resource("arrow", "assets/backgrouds/pointeur.png", TEXTURE);
    create_sprite("arrow", get_window_width() / 2 - 410, 435, "arrow");
    create_sprite("speed_paused", get_window_width() / 2 - 180, 300, "speed");
    scale_sprite("speed_paused", 0.1f);
    create_sprite("shoot_speed_paused", get_window_width() / 2 - 180, 350,
        "shoot_speed");
    scale_sprite("shoot_speed_paused", 0.1f);
    create_sprite("dammage_paused", get_window_width() / 2 - 180, 400,
        "dammage");
    scale_sprite("dammage_paused", 0.1f);
    create_sprite("range_paused", get_window_width() / 2, 300, "range");
    scale_sprite("range_paused", 0.1f);
    create_sprite("ball_speed_paused", get_window_width() / 2, 350,
        "ball_speed");
    scale_sprite("ball_speed_paused", 0.1f);
    create_sprite("luck_paused", get_window_width() / 2, 400, "luck");
    scale_sprite("luck_paused", 0.1f);
}

static void set_rect(int i, int x, int y)
{
    for (int j = 1; j <= 10; j++) {
        if (j <= i)
            sfRectangleShape_setFillColor(get_option()->pipe,
                sfColor_fromRGB(83, 60, 8));
        else
            sfRectangleShape_setFillColor(get_option()->pipe, sfBlack);
        sfRectangleShape_setSize(get_option()->pipe, (sfVector2f){5, 30});
        sfRectangleShape_setPosition(get_option()->pipe, (sfVector2f){x +
            (j * 10), y + 10});
        sfRenderWindow_drawRectangleShape(get_window(), get_option()->pipe,
            NULL);
    }
}

void load_paused_screen(void)
{
    get_ray()->texture_paused = sfTexture_create
    (get_window_width(), get_window_height());
    sfTexture_updateFromRenderWindow(get_ray()->texture_paused, get_window(),
        0, 0);
    get_ray()->paused_background = sfRectangleShape_create();
    sfRectangleShape_setSize(get_ray()->paused_background,
        (sfVector2f){get_window_width(), get_window_height()});
    sfRectangleShape_setTexture(get_ray()->paused_background,
        get_ray()->texture_paused, 1);
    get_ray()->paused_background_color = sfRectangleShape_create();
    sfRectangleShape_setSize(get_ray()->paused_background_color,
        (sfVector2f){get_window_width(), get_window_height()});
    sfRectangleShape_setFillColor(get_ray()->paused_background_color,
        (sfColor){0, 0, 0, 128});
    restart_clock("gui_action");
    load_resource("paused_background", "assets/backgrouds/paused_menu.png",
        TEXTURE);
    create_sprite("paused_background", 0, 0, "paused_background");
    center_sprite("paused_background", get_window_width() / 2, 150);
    load_paused_stats();
}

static void action_arrow(int i)
{
    if (is_control_pressed(K_ENTER) && is_clock_elapsed("gui_action")) {
        if (i == 1)
            set_screen(S_OPTIONS);
        if (i == 2)
            set_screen(S_GAME);
        if (i == 3) {
            set_screen(S_MENU);
            unload_run();
        }
    }
}

static void move_arrow(void)
{
    static int i = 2;

    if (is_control_pressed(K_UP) && is_clock_elapsed("gui_action") &&
        i > 1) {
        i--;
        play_sound("splatter02");
    }
    if (is_control_pressed(K_DOWN) && is_clock_elapsed("gui_action") &&
        i < 3) {
        i++;
        play_sound("splatter02");
    }
    if (i == 1)
        place_sprite("arrow", get_window_width() / 2 - 410, 365);
    if (i == 2)
        place_sprite("arrow", get_window_width() / 2 - 410, 435);
    if (i == 3)
        place_sprite("arrow", get_window_width() / 2 - 410, 495);
    action_arrow(i);
}

static void draw_paused_stats(void)
{
    draw_sprite("speed_paused");
    draw_sprite("shoot_speed_paused");
    draw_sprite("dammage_paused");
    draw_sprite("range_paused");
    draw_sprite("ball_speed_paused");
    draw_sprite("luck_paused");
    set_rect(get_player()->stats.speed * 5, get_window_width() / 2 - 130, 300);
    set_rect(get_player()->stats.attack_speed * 2, get_window_width() / 2 -
        130, 350);
    set_rect(get_player()->stats.damages, get_window_width() / 2 - 130, 400);
    set_rect(get_player()->stats.shoot_range, get_window_width() / 2 + 50,
        300);
    set_rect(get_player()->stats.tears_speed, get_window_width() / 2 + 50,
        350);
    set_rect(get_player()->stats.chance, get_window_width() / 2 + 50, 400);
}

void draw_paused_screen(void)
{
    sfRenderWindow_drawRectangleShape(get_window(),
        get_ray()->paused_background, NULL);
    sfRenderWindow_drawRectangleShape(get_window(),
        get_ray()->paused_background_color, NULL);
    draw_sprite("paused_background");
    draw_sprite("arrow");
    draw_paused_stats();
    move_arrow();
    if ((sfKeyboard_isKeyPressed(sfKeyEscape) ||
        sfJoystick_isButtonPressed(0, 1)) && is_clock_elapsed("gui_action"))
        set_screen(S_GAME);
}

void unload_paused_screen(void)
{
    sfTexture_destroy(get_ray()->texture_paused);
    sfRectangleShape_destroy(get_ray()->paused_background);
    sfRectangleShape_destroy(get_ray()->paused_background_color);
}
