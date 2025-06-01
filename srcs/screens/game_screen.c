/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** game_screen
*/

#include <stdio.h>

#include "actionbar.h"
#include "wolf.h"
#include "screen.h"
#include "raycaster.h"
#include "player.h"
#include "run.h"
#include "tear.h"

void load_game_screen(void)
{
    create_clock("player_movement", 0.033f);
    create_clock("shoot_clock", 0.5f);
    create_clock("bomb_clock", 0.5f);
    create_clock("pedestral_animation", 0.005f);
    restart_clock("gui_action");
    load_hud();
    sfRenderWindow_setMouseCursorGrabbed(get_window(), sfTrue);
    sfRenderWindow_setMouseCursorVisible(get_window(), sfFalse);
    sfMouse_setPositionRenderWindow((sfVector2i) {get_window_width() / 2,
        get_window_height() / 2}, get_window());
    create_sprite("crosshair", get_window_width() / 2,
        get_window_height() / 2, "crosshair");
    create_sprite("vignette", 0, 0, "vignette");
    sfSprite_setOrigin(get_sprite("crosshair")->sprite,
        (sfVector2f) {512, 512});
    scale_sprite("crosshair", 0.03f);
    stop_music("menu_music");
    set_music_volume("basement_music", 0.5f);
    play_music("basement_music");
    set_music_playing_offset("basement_music", 0.0f);
}

void draw_game_screen(void)
{
    if (is_clock_elapsed("player_movement")) {
        handle_player_angle();
        handle_player_movement();
        handle_projectiles_movements();
        apply_player_velocities();
        handle_player_shoot();
        handle_player_bomb();
    }
    sfRenderTexture_clear(get_ray()->texture, sfColor_fromRGB(10, 10, 15));
    display_rays();
    display_actionbars();
    draw_hud();
    if ((sfKeyboard_isKeyPressed(sfKeyEscape) ||
        sfJoystick_isButtonPressed(0, 6)) && is_clock_elapsed("gui_action"))
        set_screen(S_PAUSED);
}

void unload_game_screen(void)
{
    sfRenderWindow_setMouseCursorVisible(get_window(), sfTrue);
    stop_music("basement_music");
    save_run(get_run());
}
