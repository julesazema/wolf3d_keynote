/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** controller_manager
*/

#include <stdlib.h>

#include "wolf.h"
#include "option.h"

static input_type_t *local_get_input_type(void)
{
    static input_type_t input_type = I_KEYBOARD;

    return (&input_type);
}

input_type_t get_input_type(void)
{
    return (*local_get_input_type());
}

void set_input_type(input_type_t input_type)
{
    *local_get_input_type() = input_type;
}

int is_control_pressed(control_key_t key)
{
    if (key == K_ENTER)
        return (sfKeyboard_isKeyPressed(sfKeyEnter) ||
            sfJoystick_isButtonPressed(0, 0));
    if (key == K_DOWN)
        return (sfKeyboard_isKeyPressed(sfKeyDown) ||
            sfJoystick_getAxisPosition(0, sfJoystickY) > 80);
    if (key == K_UP)
        return (sfKeyboard_isKeyPressed(sfKeyUp) ||
            sfJoystick_getAxisPosition(0, sfJoystickY) < -80);
    if (key == K_JUMP)
        return (sfKeyboard_isKeyPressed(get_code_control(key)->code) ||
            sfJoystick_isButtonPressed(0, 0));
    if (key == K_SHOOT)
        return (sfMouse_isButtonPressed(sfMouseLeft) ||
            abs(sfJoystick_getAxisPosition(0, 3) > 30));
    if (key == K_PLACEBOMB)
        return (sfKeyboard_isKeyPressed(get_code_control(key)->code) ||
            abs(sfJoystick_getAxisPosition(0, 2) > 30));
    return (0);
}

void init_controllers(void)
{
}
