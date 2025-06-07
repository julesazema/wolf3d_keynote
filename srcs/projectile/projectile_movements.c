/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** projectile_movements
*/

#include <math.h>
#include <stdio.h>

#include "entity.h"
#include "list.h"
#include "run.h"
#include "tear.h"
#include "particle.h"
#include "wolf.h"

static void touch_wall(tear_t *current)
{
    create_particle((sfVector3f) {current->x, current->y, current->z},
        sfColor_fromRGBA(74, 146, 191, 200));
    remove_tear(current);
    play_sound("tear_impact0");
}

int is_in_range(double size, double x, double x2)
{
    return (fabs(x - x2) <= size);
}

static entity_t *get_ennemy(tear_t *tear)
{
    list_t *list;
    entity_t *tmp;
    room_t *current_room;
    sfVector2f size;

    current_room = get_current_room(get_run());
    list = get_current_room(get_run())->entities;
    while (list) {
        tmp = list->data;
        if (tmp->floor_id == current_room->floor_id &&
            tmp->room_id == current_room->id) {
            size = get_sprite_scale(tmp);
            if (is_in_range(size.x, tmp->x, tear->x) &&
                is_in_range(size.x, tmp->y, tear->y) &&
                is_in_range(size.y, tmp->z + size.y / 2, tear->z))
                return (tmp);
        }
        list = list->next;
    }
    return (NULL);
}

static void touch_ennemy(tear_t *current)
{
    entity_t *entity;

    entity = get_ennemy(current);
    entity->life -= get_player()->stats.damages;
    printf("ENTITY DAMAGED : life = %i/%i\n", entity->life, entity->max_life);
    create_particle((sfVector3f) {current->x, current->y, current->z},
        sfColor_fromRGBA(168, 10, 25, 200));
    remove_tear(current);
    entity->damage_ticks = 10;
    play_sound("tear_impact0");
}

static void update_velocity(tear_t *tear)
{
    tear->x += tear->vector_x;
    tear->y += tear->vector_y;
    tear->z += tear->vector_z;
}

static void handle_tears_movements(void)
{
    list_t *tears = get_tears();
    list_t *next;
    tear_t *current;
    double tmp_x;
    double tmp_y;

    while (tears) {
        current = tears->data;
        update_velocity(current);
        tmp_x = (current->x) * TILE_SIZE_INV;
        tmp_y = (current->y) * TILE_SIZE_INV;
        next = tears->next;
        if (get_ennemy(current))
            touch_ennemy(current);
        if (contains_obstacle(tmp_x, tmp_y) || is_door(tmp_x, tmp_y) ||
            current->z < 0)
            touch_wall(current);
        tears = next;
    }
}

void handle_projectiles_movements(void)
{
    handle_tears_movements();
}
