/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** control_helper
*/

#include "option.h"

char *get_name_control(sfKeyCode code)
{
    for (int i = 0; key_values[i].name; i++) {
        if (key_values[i].key == code)
            return key_values[i].name;
    }
    return NULL;
}

control_t *get_code_control(control_key_t key)
{
    return get_control()[key];
}
