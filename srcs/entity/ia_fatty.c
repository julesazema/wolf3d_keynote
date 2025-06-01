/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** ia_fatty
*/

#include "entity.h"
#include "player.h"
#include <stdio.h>

static void move_fatty(entity_t *entity)
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

void ia_fatty(entity_t *entity)
{
    create_clock("clock_fatty", 1.0f);
    if (entity->life <= 0) {
        on_entity_death(entity);
        return;
    }
    if (is_clock_elapsed("clock_fatty")) {
        entity->spritesheet.current_step++;
        if (entity->x < get_player()->x + 20 && entity->x > get_player()->x -
            20 && entity->y < get_player()->y + 10 &&
            entity->y > get_player()->y - 10) {
            get_player()->velocity_x -= 10;
            get_player()->velocity_y -= 10;
            get_player()->velocity_z += 3;
        }
        move_fatty(entity);
    }
    update_animation(entity->sprite, &entity->spritesheet);
}
