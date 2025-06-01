/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** spritesheet_manager
*/

#include <stdio.h>

#include "spritesheet.h"
#include "wolf.h"

spritesheet_t create_spritesheet(char *resource_name,
    int nb_cols, int nb_rows, int nb_steps)
{
    spritesheet_t result;

    ft_strcpy(result.resource_name, resource_name);
    result.nb_cols = nb_cols;
    result.nb_rows = nb_rows;
    result.nb_steps = nb_steps;
    result.current_step = 0;
    return (result);
}

void update_animation(sprite_t *sprite, spritesheet_t *spritesheet)
{
    resource_t *resource;
    sfVector2u texture_size;
    int tile_width;
    int tile_height;

    resource = get_resource(spritesheet->resource_name);
    if (!resource)
        return;
    if (spritesheet->current_step >= spritesheet->nb_steps)
        spritesheet->current_step = 0;
    texture_size = sfTexture_getSize(resource->data);
    tile_width = texture_size.x / spritesheet->nb_cols;
    tile_height = texture_size.y / spritesheet->nb_rows;
    sfSprite_setTexture(sprite->sprite, resource->data, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, (sfIntRect) {
        (spritesheet->current_step % spritesheet->nb_cols) * tile_width,
        (spritesheet->current_step / spritesheet->nb_cols) * tile_height,
            tile_width, tile_height});
}
