/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** draw_minimap
*/

#include <math.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include "minimap.h"
#include "wolf.h"
#include "run.h"

static void draw_current_room(room_t *current_room, int x, int y)
{
    get_minimap_room(current_room->width + 1, current_room->height + 2,
        current_room->visited, current_room->id == get_run()->current_room);
    sfRectangleShape_setPosition(get_minimap()->room, (sfVector2f){x, y});
    sfRenderTexture_drawRectangleShape(get_minimap()->minimap_texture,
        get_minimap()->room, NULL);
    for (int i = 0; icon_minimap[i].type != 0 && current_room->type !=
        CLASSIC_ROOM; i++) {
        if (icon_minimap[i].type == current_room->type) {
            sfRectangleShape_setTextureRect(get_minimap()->icon, (sfIntRect)
                {icon_minimap[i].x, icon_minimap[i].y, 14, 14});
            sfRectangleShape_setPosition(get_minimap()->icon, (sfVector2f)
                {x + current_room->width / 2 + 2, y +
                    current_room->height / 2 + 1});
            sfRenderTexture_drawRectangleShape(get_minimap()->minimap_texture,
                get_minimap()->icon, NULL);
        }
    }
    sfRenderTexture_destroy(get_minimap()->room_texture);
}

static void rec_minimap(int x, int y, int x_room, int y_room)
{
    room_t *c_room = get_room(get_current_floor(get_run()), x_room, y_room);

    if (get_minimap()->visited[c_room->id])
        return;
    draw_current_room(c_room, x, y);
    get_minimap()->visited[c_room->id] = 1;
    if (c_room->visited == 0)
        return;
    if (get_room(get_current_floor(get_run()), x_room, y_room + 1))
        rec_minimap(x, y - ((c_room->height + 2) * SIZE + 1), x_room,
            y_room + 1);
    if (get_room(get_current_floor(get_run()), x_room, y_room - 1))
        rec_minimap(x, y + ((c_room->height + 2) * SIZE + 1), x_room,
            y_room - 1);
    if (get_room(get_current_floor(get_run()), x_room + 1, y_room))
        rec_minimap(x - ((c_room->width + 1) * SIZE + 1), y,
            x_room + 1, y_room);
    if (get_room(get_current_floor(get_run()), x_room - 1, y_room))
        rec_minimap(x + ((c_room->width + 1) * SIZE + 1), y,
            x_room - 1, y_room);
}

void draw_minimap(void)
{
    sfRenderTexture_clear(get_minimap()->minimap_texture, sfTransparent);
    sfRectangleShape_setPosition(get_minimap()->minimap, (sfVector2f)
        {get_window_width() - 20, 20});
    sfRectangleShape_setPosition(get_minimap()->minimap_rect, (sfVector2f)
        {get_window_width() - 20, 20});
    sfRenderWindow_drawRectangleShape(get_window(),
        get_minimap()->minimap_rect, NULL);
    get_minimap()->visited = malloc(sizeof(int) * get_current_floor
        (get_run())->nb_rooms);
    for (int i = 0; i < get_current_floor(get_run())->nb_rooms; i++)
        get_minimap()->visited[i] = 0;
    rec_minimap(105, 55,
        get_current_room(get_run())->floor_x,
        get_current_room(get_run())->floor_y);
    sfRenderTexture_display(get_minimap()->minimap_texture);
    sfRectangleShape_setTexture(get_minimap()->minimap,
        sfRenderTexture_getTexture(get_minimap()->minimap_texture), sfTrue);
    sfRenderWindow_drawRectangleShape(get_window(), get_minimap()->minimap,
        NULL);
    free(get_minimap()->visited);
}
