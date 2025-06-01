/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** event_handler
*/

#include <math.h>
#include <player.h>

#include "item.h"
#include "option.h"
#include "particle.h"
#include "screen.h"
#include "wolf.h"

static void on_close(void)
{
    sfRenderWindow_close(get_window());
}

static void on_mouse_move(sfEvent *event)
{
    update_buttons(event->mouseMove.x, event->mouseMove.y, 0);
    update_mouse_position(event->mouseMove.x, event->mouseMove.y);
    set_input_type(I_KEYBOARD);
}

static void on_mouse_click(sfEvent *event)
{
    update_buttons(event->mouseButton.x, event->mouseButton.y,
        event->mouseButton.button == sfMouseLeft);
}

static void on_key_pressed(sfEvent *event)
{
    set_input_type(I_KEYBOARD);
    if (event->key.code == sfKeyP)
        set_screenshot();
    if (get_screen()->type == S_CONTROLS)
        on_key_pressed_controlscreen(*event);
    if (get_screen()->type == S_GAME && event->key.code == sfKeyL)
        get_player()->blue_hearth += 1;
    if (event->key.code == sfKeyF11)
        set_fullscreen();
}

static void on_joystick_button_pressed(sfEvent *event)
{
    set_input_type(I_CONTROLLER);
    (void)event;
}

static void on_joystick_axis_moved(sfEvent *event)
{
    set_input_type(I_CONTROLLER);
    (void)event;
}

void on_event(sfEvent *event)
{
    if (event->type == sfEvtClosed)
        on_close();
    if (event->type == sfEvtMouseMoved)
        on_mouse_move(event);
    if (event->type == sfEvtMouseButtonPressed)
        on_mouse_click(event);
    if (event->type == sfEvtKeyPressed)
        on_key_pressed(event);
    if (event->type == sfEvtJoystickButtonPressed)
        on_joystick_button_pressed(event);
    if (event->type == sfEvtJoystickMoved)
        on_joystick_axis_moved(event);
    if (event->type == sfEvtClosed)
        on_close();
}
