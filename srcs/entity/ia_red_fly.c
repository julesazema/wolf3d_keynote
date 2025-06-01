/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** ia_red_fly
*/

#include <math.h>
#include <stdio.h>
#include "entity.h"
#include "player.h"
#include "../../includes/player.h"

static void move_red_fly(entity_t *entity)
{
    if (entity->x > get_player()->x && !(entity->x < get_player()->x + 20))
        entity->velocity_x -= 5;
    if (entity->x < get_player()->x && !(entity->x > get_player()->x - 20))
        entity->velocity_x += 5;
    if (entity->y > get_player()->y && !(entity->y < get_player()->y + 10))
        entity->velocity_y -= 5;
    if (entity->y < get_player()->y && !(entity->y > get_player()->y - 10))
        entity->velocity_y += 5;
}

void ia_red_fly(entity_t *entity)
{
    if (entity->life <= 0) {
        on_entity_death(entity);
        return;
    }
    entity->spritesheet.current_step++;
    create_clock("touch", 2.0f);
    if (is_clock_elapsed("touch"))
        if (entity->x < get_player()->x + 30 && entity->x > get_player()->x -
            30 && entity->y < get_player()->y + 20 &&
            entity->y > get_player()->y - 20)
                damage_player(get_player(), 1);
    if (entity->life_time % 10 == 0) {
        move_red_fly(entity);
    }
    scale_sprite(entity->sprite->name, 0.4f);
    update_animation(entity->sprite, &entity->spritesheet);
}
