/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** button_utils
*/

#include "wolf.h"

void hide_button(char *button_name)
{
    button_t *button;

    button = get_button(button_name);
    if (!button)
        return;
    button->hidden = 1;
}

void show_button(char *button_name)
{
    button_t *button;

    button = get_button(button_name);
    if (!button)
        return;
    button->hidden = 0;
}

void scale_button(char *button_name, float scale)
{
    button_t *button;

    button = get_button(button_name);
    if (!button)
        return;
    sfSprite_scale(button->sprite, (sfVector2f) {scale, scale});
}

static sfIntRect get_rect(button_t *button)
{
    sfVector2u texture_size;
    int tile_width;
    int tile_height;

    texture_size = sfTexture_getSize(button->texture->data);
    tile_width = texture_size.x / 3;
    tile_height = texture_size.y;
    if (button->state == IDLE)
        return ((sfIntRect) {0, 0, tile_width, tile_height});
    if (button->state == HOVER)
        return ((sfIntRect) {tile_width, 0, tile_width, tile_height});
    if (button->state == CLICKED)
        return ((sfIntRect) {2 * tile_width, 0, tile_width, tile_height});
    return ((sfIntRect) {0, 0, 128, 128});
}

void draw_button(char *button_name)
{
    button_t *button;

    button = get_button(button_name);
    if (!button)
        return;
    sfSprite_setTextureRect(button->sprite, get_rect(button));
    sfRenderWindow_drawSprite(get_window(), button->sprite, NULL);
}
