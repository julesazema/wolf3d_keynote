/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** sprite_mover
*/

#include "wolf.h"

void move_sprite(char *sprite_name, float x, float y)
{
    sprite_t *sprite;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return;
    sfSprite_move(sprite->sprite, (sfVector2f) {x, y});
}

void place_sprite(char *sprite_name, float x, float y)
{
    sprite_t *sprite;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return;
    sfSprite_setPosition(sprite->sprite, (sfVector2f) {x, y});
}

void center_sprite(char *sprite_name, float x, float y)
{
    sprite_t *sprite;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return;
    sfSprite_setPosition(sprite->sprite, (sfVector2f)
        {x - (sfSprite_getGlobalBounds(sprite->sprite).width / 2), y});
}
