/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** ia_king_fly
*/

#include <math.h>
#include <stdio.h>
#include "entity.h"
#include "player.h"

static void move_fly(entity_t *entity, int random)
{
    if (random == 0) {
        entity->velocity_x += 10;
        entity->velocity_y += 10;
    }
    if (random == 1) {
        entity->velocity_x -= 10;
        entity->velocity_y -= 10;
    }
    if (random == 2)
        entity->velocity_x += 10;
    if (random == 3)
        entity->velocity_x -= 10;
    if (random == 4)
        entity->velocity_y += 10;
    if (random == 5)
        entity->velocity_y -= 10;
}

static void spawn_fly(entity_t *entity)
{
    int random = get_random(3);

    entity->spritesheet.current_step = 2;
    if (random == 0 || random == 1)
        create_entity(
            &get_run()->floors[entity->floor_id].rooms[entity->room_id],
            E_FLY, (sfVector3f){(float)entity->x, entity->y, entity->z});
    if (random == 2)
        create_entity(
            &get_run()->floors[entity->floor_id].rooms[entity->room_id],
            E_RED_FLY, (sfVector3f){entity->x, entity->y, entity->z});
}

void ia_king_fly(entity_t *entity)
{
    static int random = -1;

    create_clock("mouv", 3.0f);
    create_clock("clock_king_fly", 0.2f);
    create_clock("spawn_fly", 15.0f);
    if (random == -1 || is_clock_elapsed("mouv") ||
        is_entity_outside_room(entity) == 1)
        random = get_random(6);
    entity->spritesheet.current_step = 1;
    if (is_clock_elapsed("clock_king_fly"))
        move_fly(entity, random);
    if (is_clock_elapsed("spawn_fly"))
        spawn_fly(entity);
    if (entity->life <= 0)
        return (on_entity_death(entity));
    scale_sprite(entity->sprite->name, 2.0f);
    update_animation(entity->sprite, &entity->spritesheet);
}
