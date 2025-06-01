/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** set_option
*/

#include <SFML/Window/Keyboard.h>

#include "option.h"
#include "raycaster.h"
#include "wolf.h"

void set_fullscreen(void)
{
    get_option()->fullscreen = !get_option()->fullscreen;
    destroy_window();
    init_window(1280, 720, "Wolf3D", get_option()->fullscreen);
    unload_ray();
    init_ray();
}

void set_controls(void)
{
}
