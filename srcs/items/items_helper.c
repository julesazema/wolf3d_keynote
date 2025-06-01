/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** items_helper
*/

#include <stdlib.h>

#include "actionbar.h"
#include "item.h"
#include "player.h"
#include "wolf.h"

void pickup_item(dropped_item_t *dropped_item)
{
    const item_t *item;

    item = dropped_item->ref;
    if (item == NULL)
        return;
    display_title(item->display_name, item->description, 2);
    item->pickup();
    remove_dropped_item(dropped_item);
    play_sound("pillpickup");
    ft_lstadd_back(&get_player()->inventory.items,
        ft_createnode((item_t *) item, NULL));
}

int has_item(item_type_t type)
{
    list_t *list;
    item_t *tmp;

    list = get_player()->inventory.items;
    while (list) {
        tmp = (item_t *) list->data;
        if (tmp->type == type)
            return (1);
        list = list->next;
    }
    return (0);
}
