/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** ia_fly
*/

#include "entity.h"
#include "player.h"
#include <stdio.h>

static void move_fly(entity_t *entity)
{
    int random = get_random(4);

    if (random == 0)
        entity->velocity_x += 15;
    if (random == 1)
        entity->velocity_x -= 15;
    if (random == 2)
        entity->velocity_y += 15;
    if (random == 3)
        entity->velocity_y -= 15;
}

void ia_fly(entity_t *entity)
{
    if (entity->life <= 0) {
        on_entity_death(entity);
        return;
    }
    create_clock("clock_fly", 0.2f);
    create_clock("touch", 2.0f);
    if (is_clock_elapsed("touch")) {
        if (entity->x < get_player()->x + 40 && entity->x > get_player()->x -
            30 && entity->y < get_player()->y + 30 &&
            entity->y > get_player()->y - 30) {
            damage_player(get_player(), 1);
        }
    }
    if (is_clock_elapsed("clock_fly"))
        move_fly(entity);
    entity->z = TILE_SIZE / 3.0f;
    entity->spritesheet.current_step++;
    update_animation(entity->sprite, &entity->spritesheet);
}
