/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** text_helper
*/

#include "wolf.h"

void show_text(char *text_name)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    text->hidden = 0;
}

void hide_text(char *text_name)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    text->hidden = 1;
}

void center_text(char *text_name, int x, int y)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    move_text(text_name, x - sfText_getLocalBounds(text->text).width / 2, y);
}

void center_text_origin(char *text_name)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    sfText_setOrigin(text->text, (sfVector2f)
        {
            sfText_getLocalBounds(text->text).width / 2,
            sfText_getLocalBounds(text->text).height / 2
        });
}
