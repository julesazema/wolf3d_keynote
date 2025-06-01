/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** text_displayer
*/

#include "wolf.h"

void draw_text(char *text_name)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    sfRenderWindow_drawText(get_window(), text->text, NULL);
}
