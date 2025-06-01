/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** sprite_helper
*/

#include "wolf.h"
#include "list.h"

void draw_sprite(char *sprite_name)
{
    sprite_t *sprite;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return;
    sfRenderWindow_drawSprite(get_window(), sprite->sprite, NULL);
}

void rotate_sprite(char *sprite_name, float angle)
{
    sprite_t *sprite;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return;
    sfSprite_rotate(sprite->sprite, angle);
}

sfVector2f get_sprite_size(char *sprite_name)
{
    sprite_t *sprite;
    sfFloatRect rect;

    sprite = get_sprite(sprite_name);
    if (sprite == NULL)
        return ((sfVector2f) {0, 0});
    rect = sfSprite_getLocalBounds(sprite->sprite);
    return ((sfVector2f) {rect.width, rect.height});
}
