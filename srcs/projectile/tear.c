/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** tear
*/

#include "list.h"
#include "player.h"
#include "tear.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#include "wolf.h"

static list_t **local_get_tears(void)
{
    static list_t *tears = NULL;

    return (&tears);
}

list_t *get_tears(void)
{
    return (*local_get_tears());
}

void launch_tear(player_t *player)
{
    tear_t *tear;
    double v_x = cos(player->yaw) * cos(player->pitch / 360) * 15.0f;
    double v_y = sin(player->yaw) * cos(player->pitch / 360) * 15.0f;
    double v_z = sin(player->pitch / 360) * 15.0f;

    tear = malloc(sizeof(tear_t));
    if (!tear)
        return;
    tear->x = player->x;
    tear->y = player->y;
    tear->z = player->z * 2 + TILE_SIZE / 2;
    tear->vector_x = v_x;
    tear->vector_y = v_y;
    tear->vector_z = v_z;
    play_sound("tear_fire0");
    ft_lstadd_back(local_get_tears(), ft_createnode(tear, NULL));
}

int is_tear(int x, int y)
{
    list_t *list;
    tear_t *current;

    list = get_tears();
    while (list) {
        current = list->data;
        if (current->x == x && current->y == y)
            return (1);
        list = list->next;
    }
    return (0);
}

void remove_tear(tear_t *tear)
{
    list_t *list = *local_get_tears();
    list_t *previous = NULL;
    list_t *new_next = NULL;

    while (list) {
        if (list->data == tear)
            break;
        previous = list;
        list = list->next;
    }
    if (!list)
        return;
    if (!previous) {
        *local_get_tears() = list->next;
        return;
    }
    if (list->next)
        new_next = list->next;
    free_node(list);
    previous->next = new_next;
}
