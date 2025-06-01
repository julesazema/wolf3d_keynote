/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** text_utils
*/

#include "wolf.h"

void change_text(char *text_name, char *content)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    sfText_setString(text->text, content);
}

void move_text(char *text_name, int x, int y)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    sfText_setPosition(text->text, (sfVector2f) {x, y});
}

void scale_text(char *text_name, int scale)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    sfText_setCharacterSize(text->text, scale);
}

void colorize_text(char *text_name, sfColor color)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    sfText_setColor(text->text, color);
}

void outline_text(char *text_name, float thickness, sfColor color)
{
    text_t *text;

    text = get_text(text_name);
    if (!text)
        return;
    sfText_setOutlineThickness(text->text, thickness);
    sfText_setOutlineColor(text->text, color);
}
