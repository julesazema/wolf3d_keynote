/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** items_manager
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "list.h"
#include "run.h"
#include "wolf.h"

static const item_t items[] = {
    {"<3", "assets/items/heart.png", "HP up",
        I_HEART, &on_heart_pickup, 4},
    {"Toothpicks", "assets/items/toothpicks.png", "Tears + shot speed up",
        I_TOOTHPICKS, &on_toothpick_pickup, 4},
    {"Synthoil", "assets/items/synthoil.png", "DMG up + range",
        I_SYNTHOIL, &on_sinthoil_pickup, 4},
    {"Cricket's head", "assets/items/cricket_head.png", "DMG up",
        I_CRICKETS_HEAD, &on_crickets_head_pickup, 4},
    {"A dollar", "assets/items/dollar.png", "$$$",
        I_DOLLAR, &on_dollar_pickup, 4},
    {"boom!", "assets/items/boom!.png", "10 bombs",
        I_BOOM, &on_boom_pickup, 4},
    {"odd_mushroom", "assets/items/odd_mushroom.png", "DMG up",
        I_ODD_MUSHROOM, &on_odd_mushroom_pickup, 4},
    {"cat_o_nine_tails", "assets/items/cat_o_nine_tails.png",
        "Shot sped up + DMG up",
        I_CAT_O_NINE_TAILS, &on_cat_o_nine_tails_pickup, 4},
    {"number_one", "assets/items/number_one.png", "Tears up",
        I_NUMBER_ONE, &on_number_one_pickup, 4},
    {"polyphemus", "assets/items/polyphemus.png", "Mega tears",
        I_POLYPHEMUS, &on_polyphemus_pickup, 4},
    {"sad onion", "assets/items/sad_onion.png", "Tears up",
        I_SAD_ONION, &on_sad_onion_pickup, 4},
    {"a quarter", "assets/items/a_quarter.png", "+25 coins",
        I_A_QUARTER, &on_a_quarter_pickup, 4},
    {"small rock", "assets/items/small_rock.png", "DMG up",
        I_SMALL_ROCK, &on_small_rock_pickup, 4},
    {"pyromaniac", "assets/items/pyromaniac.png", "It hurt so good +5 Bombs",
        I_PYROMANIA, &on_pyromania_pickup, 4},
    {"rosary", "assets/items/rosary.png", "Tears + Faith up",
        I_ROSARY, &on_rosary_pickup, 4},
    {0, 0, 0, 0, 0, 0}
};

const item_t *get_item_by_type(item_type_t type)
{
    int i;

    i = 0;
    while (items[i].display_name != 0) {
        if (items[i].type == type)
            return (&items[i]);
        i++;
    }
    return (NULL);
}

int count_available_items(void)
{
    int i;

    i = 0;
    while (items[i].display_name != 0)
        i++;
    return (i);
}

const item_t *get_random_item(void)
{
    int max = count_available_items();
    int i = 0;
    int total_chance = 0;
    int sum = 0;
    int random;

    i = 0;
    while (i < max) {
        total_chance += items[i].chance_to_drop;
        i++;
    }
    random = get_random(total_chance);
    i = 0;
    while (i < max) {
        sum += items[i].chance_to_drop;
        if (random < sum)
            return (&items[i]);
        i++;
    }
    return (&items[0]);
}

void remove_dropped_item(dropped_item_t *dropped_pickup)
{
    list_t *list = get_current_room(get_run())->items;
    list_t *previous = NULL;
    list_t *new_next = NULL;

    while (list) {
        if (list->data == dropped_pickup)
            break;
        previous = list;
        list = list->next;
    }
    if (!list)
        return;
    if (!previous) {
        get_current_room(get_run())->items = list->next;
        return;
    }
    if (list->next)
        new_next = list->next;
    free_node(list);
    previous->next = new_next;
}
