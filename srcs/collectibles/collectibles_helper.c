/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** collectibles_helper
*/

#include <stdlib.h>

#include "collectible.h"
#include "player.h"
#include "run.h"
#include "wolf.h"

void pickup_collectible(dropped_collectible_t *dropped_pickup)
{
    const collectible_t *collectible;

    collectible = dropped_pickup->ref;
    if (collectible == NULL)
        return;
    if (get_current_room(get_run())->type == SHOP &&
        collectible->shop_price > get_player()->inventory.coins)
        return;
    if (!collectible->pickup())
        return;
    if (get_current_room(get_run())->type == SHOP)
        get_player()->inventory.coins -= collectible->shop_price;
    remove_dropped_pickup(dropped_pickup);
    play_sound("pillpickup");
}

void drop_collectible(list_t **dest, double x, double y)
{
    dropped_collectible_t *tmp;

    tmp = malloc(sizeof(dropped_collectible_t));
    if (!tmp)
        return;
    tmp->x = x;
    tmp->y = y;
    tmp->z = 0;
    tmp->ref = get_random_collectible();
    ft_lstadd_back(dest, ft_createnode(tmp, NULL));
}
