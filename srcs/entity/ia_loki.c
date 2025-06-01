/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ia_loki
*/

#include "entity.h"
#include "player.h"

static void is_touch(entity_t *entity)
{
    create_clock("touch", 0.5f);
    if (is_clock_elapsed("touch"))
        if (entity->x < get_player()->x + 20 && entity->x > get_player()->x -
        20 && entity->y < get_player()->y + 10 &&
        entity->y > get_player()->y - 10)
            damage_player(get_player(), 1);
}

void ia_loki(entity_t *entity)
{
    double x_movement;
    double y_movement;

    if (entity->life <= 0) {
        on_entity_death(entity);
        return;
    }
    create_clock("loki_animation", 0.5f);
    if (is_clock_elapsed("loki_animation"))
        entity->spritesheet.current_step = 1;
    else
        entity->spritesheet.current_step = 0;
    update_animation(entity->sprite, &entity->spritesheet);
    x_movement = entity->x - get_player()->x > 0 ? -1.5f : 1.5f;
    y_movement = entity->y - get_player()->y > 0 ? -1.5f : 1.5f;
    is_touch(entity);
    entity->velocity_x = x_movement;
    entity->velocity_y = y_movement;
}
