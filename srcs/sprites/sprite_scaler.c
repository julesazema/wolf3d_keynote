/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** sprite_scaler
*/

#include "wolf.h"

void scale_sprite(char *sprite_name, float factor)
{
    sprite_t *sprite;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return;
    sfSprite_scale(sprite->sprite, (sfVector2f) {factor, factor});
}

void rescale_sprite(char *sprite_name, float factor)
{
    sprite_t *sprite;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return;
    sfSprite_setScale(sprite->sprite, (sfVector2f) {factor, factor});
}

void resize_sprite(char *sprite_name, float x, float y)
{
    sprite_t *sprite;
    sfFloatRect bounds;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return;
    bounds = sfSprite_getLocalBounds(sprite->sprite);
    sfSprite_setScale(sprite->sprite,
        (sfVector2f) {x / bounds.width, y / bounds.height});
}
