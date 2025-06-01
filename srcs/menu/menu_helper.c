/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** menu_helper
*/

#include <SFML/Graphics/Color.h>
#include "wolf.h"

void create_menu_text(char *name, char *text, int scale)
{
    create_text(name, text, "isaac_font");
    colorize_text(name, sfColor_fromRGB(83, 60, 8));
    scale_text(name, scale);
}
