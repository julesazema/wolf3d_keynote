/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** minimap_manager
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderTexture.h>

#include "minimap.h"
#include "wolf.h"

static minimap_t **local_get_minimap(void)
{
    static minimap_t *minimap = NULL;

    return (&minimap);
}

static void init_minimap_rect(minimap_t *minimap)
{
    sfRectangleShape_setSize(minimap->minimap, (sfVector2f){250, 150});
    sfRectangleShape_setOrigin(minimap->minimap, (sfVector2f){250, 0});
    sfRectangleShape_setSize(minimap->minimap_rect, (sfVector2f){250, 150});
    sfRectangleShape_setOrigin(minimap->minimap_rect, (sfVector2f){250, 0});
    sfRectangleShape_setFillColor(minimap->minimap_rect,
        (sfColor){0, 0, 0, 100});
    sfRectangleShape_setOutlineColor(minimap->minimap_rect, sfBlack);
    sfRectangleShape_setOutlineThickness(minimap->minimap_rect, -5);
    sfRectangleShape_setSize(minimap->icon, (sfVector2f){30, 30});
    sfRectangleShape_setTexture(minimap->icon, get_resource
        ("minimap")->data, sfTrue);
}

void init_minimap(void)
{
    minimap_t *minimap;

    minimap = malloc(sizeof(minimap_t));
    if (!minimap)
        return;
    load_resource("minimap", "assets/minimap/minimapapi_icons.png", TEXTURE);
    minimap->pixel = sfRectangleShape_create();
    minimap->room = sfRectangleShape_create();
    minimap->corner = sfRectangleShape_create();
    minimap->room_texture = NULL;
    minimap->minimap_texture = sfRenderTexture_create(250, 150, sfTrue);
    minimap->minimap = sfRectangleShape_create();
    minimap->minimap_rect = sfRectangleShape_create();
    minimap->icon = sfRectangleShape_create();
    init_minimap_rect(minimap);
    *local_get_minimap() = minimap;
}

minimap_t *get_minimap(void)
{
    return (*local_get_minimap());
}

void unload_minimap(void)
{
    sfRenderTexture_destroy(get_minimap()->minimap_texture);
    sfRectangleShape_destroy(get_minimap()->minimap);
    sfRectangleShape_destroy(get_minimap()->minimap_rect);
    sfRectangleShape_destroy(get_minimap()->corner);
    sfRectangleShape_destroy(get_minimap()->room);
    sfRectangleShape_destroy(get_minimap()->pixel);
    sfRectangleShape_destroy(get_minimap()->icon);
    free(get_minimap());
}
