/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ia_slime
*/

#include "entity.h"
#include "player.h"

void ia_slime(entity_t *entity)
{
    double x_movement;
    double y_movement;

    create_clock("touch", 0.5f);
    if (entity->life <= 0) {
        on_entity_death(entity);
        return;
    }
    if (get_random(40) == 0)
        entity->spritesheet.current_step += 4;
    x_movement = entity->x - get_player()->x > 0 ? -0.5f : 0.5f;
    y_movement = entity->y - get_player()->y > 0 ? -0.5f : 0.5f;
    entity->velocity_x += x_movement / 2;
    entity->velocity_y += y_movement / 2;
    if (is_clock_elapsed("touch"))
        if (entity->x < get_player()->x + 20 && entity->x > get_player()->x -
        20 && entity->y < get_player()->y + 10 &&
        entity->y > get_player()->y - 10)
            damage_player(get_player(), 1);
    update_animation(entity->sprite, &entity->spritesheet);
}
