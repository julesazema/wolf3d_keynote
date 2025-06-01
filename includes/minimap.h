/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** minimap
*/

#ifndef MINIMAP_H
    #define MINIMAP_H

    #define SIZE_WALL 3
    #define SIZE 6

    #include <SFML/Graphics/Types.h>
    #include "run.h"

typedef struct minimap_s {
    sfRenderTexture *room_texture;
    sfRectangleShape *pixel;
    sfRectangleShape *room;
    sfRectangleShape *corner;
    sfRenderTexture *minimap_texture;
    sfRectangleShape *minimap;
    sfRectangleShape *minimap_rect;
    sfRectangleShape *icon;
    int *visited;
} minimap_t;

typedef struct room_to_minimap_s {
    room_type_t type;
    int x;
    int y;
} room_to_minimap_t;

static const room_to_minimap_t icon_minimap[] = {
    {ITEM_ROOM, 4 * 16, 0},
    {BOSS_ROOM, 16, 16},
    {MINIBOSS_ROOM, 0, 16},
    {SHOP, 0, 0},
    {SECRET_ROOM, 16, 0},
    {SUPER_SECRET_ROOM, 2 * 16, 0},
    {CURSE_ROOM, 4 * 16, 16},
    {SACRIFICE_ROOM, 5 * 16, 16},
    {CHALLENGE_ROOM, 2 * 16, 16},
    {ARCADE, 6 * 16, 16},
    {LIBRARY, 3 * 16, 0},
    {DICE_ROOM, 7 * 16, 0},
    {0, 0, 0}
};

void draw_minimap(void);

minimap_t *get_minimap(void);
void init_minimap(void);
void unload_minimap(void);

void get_minimap_room(int width, int height, int visited, int current);

#endif //MINIMAP_H
