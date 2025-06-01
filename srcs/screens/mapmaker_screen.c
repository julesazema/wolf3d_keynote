/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** mapmaker_screen
*/

#include <math.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.h>
#include "mapmaker.h"
#include "minimap.h"
#include "screen.h"
#include "wolf.h"

static mapmaker_t **local_get_mapmaker(void)
{
    static mapmaker_t *mapmaker = NULL;

    return (&mapmaker);
}

void load_mapmaker_screen(void)
{
    create_text("mapmaker", "Run Maker", "font");
    scale_text("mapmaker", 40);
    center_text("mapmaker", get_window_width() / 2, 50);
    *local_get_mapmaker() = init_mapmaker();
    stop_music("menu_music");
    play_music("mapmaker_music");
}

static sfColor get_room_color(room_type_t type)
{
    if (type == BOSS_ROOM)
        return (sfColor_fromRGB(255, 50, 51));
    if (type == SHOP)
        return (sfColor_fromRGB(255, 153, 51));
    if (type == ITEM_ROOM)
        return (sfColor_fromRGB(255, 210, 26));
    if (type == SACRIFICE_ROOM)
        return (sfColor_fromRGB(15, 32, 64));
    return (sfColor_fromRGB(51, 51, 51));
}

static void draw_floor_outline(sfRectangleShape *shape, int y_pos)
{
    sfRectangleShape_setOutlineThickness(shape, 1);
    sfRectangleShape_setOutlineColor(shape,
        sfColor_fromRGB(255, 255, 240));
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setPosition(shape, (sfVector2f)
        {get_window_width() / 4, y_pos});
    sfRectangleShape_setSize(shape, (sfVector2f)
        {get_window_width() / 2, 130});
    sfRenderWindow_drawRectangleShape(get_window(), shape, NULL);
}

static void draw_floor(mapmaker_t *mapmaker, int floor_index, int y_pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    int i;
    int x_offset;

    if (mapmaker->run.current_floor == floor_index)
        draw_floor_outline(rect, y_pos);
    x_offset = get_window_width() / 2 -
        (31 * mapmaker->run.floors[floor_index].nb_rooms / 2);
    sfRectangleShape_setSize(rect, (sfVector2f) {30, 30});
    i = 0;
    while (i < mapmaker->run.floors[floor_index].nb_rooms) {
        sfRectangleShape_setFillColor(rect,
            get_room_color(mapmaker->run.floors[floor_index].rooms[i].type));
        sfRectangleShape_setPosition(rect, (sfVector2f)
            {x_offset + (i * 31), y_pos + 85});
        sfRenderWindow_drawRectangleShape(get_window(), rect, NULL);
        i++;
    }
    sfRectangleShape_destroy(rect);
}

static void draw_contents(mapmaker_t *mapmaker)
{
    char tmp[64];
    char tmp_2[64];
    int y_offset;
    int i;

    if (mapmaker->state != S_GLOBAL)
        return;
    ft_strcpy(tmp, "mapmaker_floor_");
    ft_strcpy(tmp_2, "Floor ");
    y_offset = get_window_height() / 2 - (140 * mapmaker->run.nb_floors) + 70;
    i = 0;
    while (i < mapmaker->run.nb_floors) {
        ft_itoad(i, tmp + ft_strlen(tmp), 64 - ft_strlen(tmp));
        ft_itoad(i, tmp_2 + ft_strlen("Floor "), 64 - ft_strlen("Floor "));
        create_text(tmp, tmp_2, "font");
        center_text(tmp, get_window_width() / 2, y_offset + (i * 140) + 15);
        draw_text(tmp);
        draw_floor(mapmaker, i, y_offset + (i * 140));
        i++;
    }
}

void draw_mapmaker_screen(void)
{
    sfRenderWindow_clear(get_window(), sfColor_fromRGB(10, 12, 15));
    draw_text("mapmaker");
    draw_contents(*local_get_mapmaker());
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && is_clock_elapsed("gui_action"))
        set_screen(S_MENU);
}

void unload_mapmaker_screen(void)
{
    stop_music("mapmaker_music");
    play_music("menu_music");
    free(*local_get_mapmaker());
}
