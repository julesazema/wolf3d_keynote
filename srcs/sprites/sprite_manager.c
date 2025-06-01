/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** resource_manager
*/

#include <stdlib.h>
#include "list.h"
#include "wolf.h"

static list_t **local_get_sprites(void)
{
    static list_t *sprites = NULL;

    return (&sprites);
}

static sfSprite *init_sprite(int x, int y, resource_t *resource)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, resource->data, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f) {x, y});
    return (sprite);
}

sprite_t *create_sprite(char *name, int x, int y, char *resource_name)
{
    sprite_t *result;
    resource_t *resource = get_resource(resource_name);

    if (resource == NULL || resource->type != TEXTURE)
        return (NULL);
    result = malloc(sizeof(sprite_t));
    if (!result)
        return (NULL);
    ft_strcpy(result->name, name);
    result->sprite = init_sprite(x, y, resource);
    result->resource = resource;
    *local_get_sprites() = ft_createnode(result, *local_get_sprites());
    return (result);
}

sprite_t *get_sprite(char *name)
{
    list_t *current;

    current = *local_get_sprites();
    while (current) {
        if (ft_strcmp(((sprite_t *)current->data)->name, name) == 0)
            return (current->data);
        current = current->next;
    }
    return (NULL);
}

void unload_sprites(void)
{
    list_t *current;
    list_t *next;

    current = *local_get_sprites();
    while (current) {
        next = current->next;
        sfSprite_destroy(((sprite_t *)current->data)->sprite);
        free(current->data);
        free(current);
        current = next;
    }
    *local_get_sprites() = NULL;
}
