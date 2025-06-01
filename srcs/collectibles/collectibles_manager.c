/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** collectibles_manager
*/

#include <stddef.h>
#include <stdlib.h>

#include "collectible.h"
#include "list.h"
#include "run.h"
#include "wolf.h"

static const collectible_t collectibles[] = {
    {"Red Heart", "red_heart", "assets/pickups/red_heart.png",
        C_RED_HEART, &on_red_heart_pickup, 5, 40},
    {"Half Red Heart", "half_red_heart", "assets/pickups/half_red_heart.png",
        C_HALF_RED_HEART, &on_half_red_heart_pickup, 5, 40},
    {"Penny", "penny", "assets/pickups/penny.png",
        C_PENNY, &on_penny_pickup, 5, 92},
    {"Nickel", "nickel", "assets/pickups/nickel.png",
        C_NICKEL, &on_nickel_pickup, 5, 5},
    {"Dime", "dime", "assets/pickups/dime.png",
        C_DIME, &on_dime_pickup, 5, 1},
    {"Bomb", "bomb", "assets/pickups/bomb.png",
        C_BOMB, &on_bomb_pickup, 5, 75},
    {"Double Bomb", "double_bomb", "assets/pickups/double_bomb.png",
        C_DOUBLE_BOMB, &on_double_bomb_pickup, 5, 12},
    {0, 0, 0, 0, 0, 0, 0}
};

void load_collectibles_resources(void)
{
    int i;

    i = 0;
    while (collectibles[i].display_name != 0) {
        load_resource(collectibles[i].resource_name,
            collectibles[i].resource_path, TEXTURE);
        i++;
    }
}

collectible_t *get_collectible_by_type(pickup_type_t type)
{
    int i;

    i = 0;
    while (collectibles[i].display_name != 0) {
        if (collectibles[i].type == type)
            return ((collectible_t *) &collectibles[i]);
        i++;
    }
    return (NULL);
}

int count_available_collectibles(void)
{
    int i;

    i = 0;
    while (collectibles[i].display_name != 0)
        i++;
    return (i);
}

const collectible_t *get_random_collectible(void)
{
    int max = count_available_collectibles();
    int i = 0;
    int total_chance = 0;
    int sum = 0;
    int random;

    i = 0;
    while (i < max) {
        total_chance += collectibles[i].chance_to_drop;
        i++;
    }
    random = get_random(total_chance);
    i = 0;
    while (i < max) {
        sum += collectibles[i].chance_to_drop;
        if (random < sum)
            return (&collectibles[i]);
        i++;
    }
    return (&collectibles[0]);
}

void remove_dropped_pickup(dropped_collectible_t *dropped_pickup)
{
    list_t *list = get_current_room(get_run())->collectibles;
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
        get_current_room(get_run())->collectibles = list->next;
        return;
    }
    if (list->next)
        new_next = list->next;
    free_node(list);
    previous->next = new_next;
}
