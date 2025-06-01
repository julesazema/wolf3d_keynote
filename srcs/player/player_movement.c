/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_movement
*/

#include <tgmath.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>

#include "option.h"
#include "player.h"
#include "wolf.h"

static void handle_mouse_movement(double *yaw_diff, double *pitch_diff)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(get_window());
    sfVector2i center =
        {(int)get_window_width() / 2, (int)get_window_height() / 2};

    if (mouse_pos.x == center.x && mouse_pos.y == center.y)
        return;
    *yaw_diff = (mouse_pos.x - center.x);
    *pitch_diff = (mouse_pos.y - center.y) * 150;
    sfMouse_setPositionRenderWindow(center, get_window());
}

static void handle_joystick_movement(double *yaw_diff, double *pitch_diff)
{
    if (sfJoystick_getAxisPosition(0, sfJoystickU) > 30 ||
        sfJoystick_getAxisPosition(0, sfJoystickU) < -30)
        *yaw_diff = (sfJoystick_getAxisPosition(0, sfJoystickU)) * 2;
    if (sfJoystick_getAxisPosition(0, sfJoystickV) > 30 ||
        sfJoystick_getAxisPosition(0, sfJoystickV) < -30)
        *pitch_diff = (sfJoystick_getAxisPosition(0, sfJoystickV)) * 300;
}

void handle_player_angle(void)
{
    player_t *player = get_player();
    double delta = 0.001f;
    double yaw_diff = 0;
    double pitch_diff = 0;

    if (get_input_type() == I_KEYBOARD)
        handle_mouse_movement(&yaw_diff, &pitch_diff);
    if (get_input_type() == I_CONTROLLER)
        handle_joystick_movement(&yaw_diff, &pitch_diff);
    player->yaw += (yaw_diff * delta);
    player->pitch -= (pitch_diff * delta);
    if (player->yaw > M_PI)
        player->yaw -= 2 * M_PI;
    if (player->yaw < -2 * M_PI)
        player->yaw += 2 * M_PI;
}

static double calc_x_velocity(double dest_x, double dest_y)
{
    double result = 0;

    if (sfKeyboard_isKeyPressed(get_code_control(K_MOVE_FORWARD)->code) ||
        sfJoystick_getAxisPosition(0, sfJoystickY) < -40)
        result += dest_x;
    if (sfKeyboard_isKeyPressed(get_code_control(K_MOVE_BACKWARD)->code) ||
        sfJoystick_getAxisPosition(0, sfJoystickY) > 40)
        result -= dest_x;
    if (sfKeyboard_isKeyPressed(get_code_control(K_MOVE_RIGHT)->code) ||
        sfJoystick_getAxisPosition(0, sfJoystickX) > 40)
        result -= dest_y;
    if (sfKeyboard_isKeyPressed(get_code_control(K_MOVE_LEFT)->code) ||
        sfJoystick_getAxisPosition(0, sfJoystickX) < -40)
        result += dest_y;
    return (result);
}

static double calc_y_velocity(double dest_x, double dest_y)
{
    double result = 0;

    if (sfKeyboard_isKeyPressed(get_code_control(K_MOVE_FORWARD)->code) ||
        sfJoystick_getAxisPosition(0, sfJoystickY) < -40)
        result += dest_y;
    if (sfKeyboard_isKeyPressed(get_code_control(K_MOVE_BACKWARD)->code) ||
        sfJoystick_getAxisPosition(0, sfJoystickY) > 40)
        result -= dest_y;
    if (sfKeyboard_isKeyPressed(get_code_control(K_MOVE_RIGHT)->code) ||
        sfJoystick_getAxisPosition(0, sfJoystickX) > 40)
        result += dest_x;
    if (sfKeyboard_isKeyPressed(get_code_control(K_MOVE_LEFT)->code) ||
        sfJoystick_getAxisPosition(0, sfJoystickX) < -40)
        result -= dest_x;
    return (result);
}

void handle_player_movement(void)
{
    player_t *player = get_player();
    double v_x = cos(player->yaw) * 1.5;
    double v_y = sin(player->yaw) * 1.5;
    double x_add;
    double y_add;

    x_add = calc_x_velocity(v_x, v_y);
    y_add = calc_y_velocity(v_x, v_y);
    if (fabs(x_add) > 0 || fabs(y_add) > 0) {
        player->velocity_x += x_add * player->stats.speed;
        player->velocity_y += y_add * player->stats.speed;
    }
    if (is_control_pressed(K_JUMP))
        run_player_action(JUMP);
}
