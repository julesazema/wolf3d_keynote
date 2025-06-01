/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** inventory_drawer
*/

#include "item.h"
#include "player.h"
#include "wolf.h"

item_t *get_item_name(int index)
{
    list_t *list;
    int i;

    i = 0;
    list = get_player()->inventory.items;
    while (list) {
        if (i == index)
            return (list->data);
        list = list->next;
        i++;
    }
    return NULL;
}

int size_inventory(void)
{
    list_t *list;
    int i = 0;

    list = get_player()->inventory.items;
    while (list) {
        list = list->next;
        i++;
    }
    return (i);
}

void draw_inventory(void)
{
    item_t *item;
    int x = 1100;
    int y = 200;

    for (int size = size_inventory(); size > 0; size--) {
        item = get_item_name(size - 1);
        if (!item)
            break;
        load_resource(item->display_name, item->resource_name, TEXTURE);
        create_sprite(item->display_name, x + get_window_width() - 1280,
            y + get_window_height() - 720, item->display_name);
        scale_sprite(item->display_name, 2);
        if (y < 650)
            draw_sprite(item->display_name);
        x += 50;
        if (x > 1200) {
            x = 1100;
            y += 50;
        }
    }
}
