/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** get_minimap_room
*/

#include "minimap.h"
#include "wolf.h"

static void set_corner(int width, int height,
    sfRenderTexture *texture)
{
    sfRectangleShape_setPosition(get_minimap()->corner, (sfVector2f)
        {SIZE_WALL, SIZE_WALL});
    sfRenderTexture_drawRectangleShape(texture, get_minimap()->corner, NULL);
    sfRectangleShape_setPosition(get_minimap()->corner, (sfVector2f)
        {width * SIZE - (SIZE_WALL * 2), SIZE_WALL});
    sfRenderTexture_drawRectangleShape(texture, get_minimap()->corner, NULL);
    sfRectangleShape_setPosition(get_minimap()->corner, (sfVector2f)
        {SIZE_WALL, height * SIZE - (SIZE_WALL * 2)});
    sfRenderTexture_drawRectangleShape(texture, get_minimap()->corner, NULL);
    sfRectangleShape_setPosition(get_minimap()->corner, (sfVector2f)
        {width * SIZE - (SIZE_WALL * 2), height * SIZE - (SIZE_WALL * 2)});
    sfRenderTexture_drawRectangleShape(texture, get_minimap()->corner, NULL);
}

static void set_outline(int width, int height,
    sfRenderTexture *texture)
{
    for (int i = 0; i < width * SIZE; i++) {
        sfRectangleShape_setPosition(get_minimap()->pixel, (sfVector2f){i, 0});
        sfRenderTexture_drawRectangleShape(texture,
            get_minimap()->pixel, NULL);
        sfRectangleShape_setPosition(get_minimap()->pixel, (sfVector2f)
            {i, height * SIZE - SIZE_WALL});
        sfRenderTexture_drawRectangleShape(texture, get_minimap()->pixel,
            NULL);
    }
    for (int i = 0; i < height * SIZE; i++) {
        sfRectangleShape_setPosition(get_minimap()->pixel, (sfVector2f)
            {0, i});
        sfRenderTexture_drawRectangleShape(texture, get_minimap()->pixel,
            NULL);
        sfRectangleShape_setPosition(get_minimap()->pixel, (sfVector2f)
            {width * SIZE - SIZE_WALL, i});
        sfRenderTexture_drawRectangleShape(texture, get_minimap()->pixel,
            NULL);
    }
}

static void set_rectangle_propriety(int width, int height)
{
    sfRectangleShape_setSize(get_minimap()->corner, (sfVector2f){SIZE_WALL,
        SIZE_WALL});
    sfRectangleShape_setSize(get_minimap()->pixel, (sfVector2f){SIZE_WALL,
        SIZE_WALL});
    sfRectangleShape_setFillColor(get_minimap()->corner, sfBlack);
    sfRectangleShape_setFillColor(get_minimap()->pixel, sfBlack);
    sfRectangleShape_setSize(get_minimap()->room, (sfVector2f){width * SIZE,
        height * SIZE});
}

void get_minimap_room(int width, int height, int visited, int current)
{
    get_minimap()->room_texture = sfRenderTexture_create(width * SIZE,
        height * SIZE, sfFalse);
    set_rectangle_propriety(width, height);
    if (visited && current)
        sfRenderTexture_clear(get_minimap()->room_texture, sfWhite);
    if (visited && !current)
        sfRenderTexture_clear(get_minimap()->room_texture, (sfColor)
            {160, 160, 160, 255});
    if (!visited && !current)
        sfRenderTexture_clear(get_minimap()->room_texture, (sfColor)
            {70, 70, 70, 255});
    set_outline(width, height, get_minimap()->room_texture);
    set_corner(width, height, get_minimap()->room_texture);
    sfRenderTexture_display(get_minimap()->room_texture);
    sfRectangleShape_setTexture(get_minimap()->room,
        sfRenderTexture_getTexture(get_minimap()->room_texture), sfTrue);
}
