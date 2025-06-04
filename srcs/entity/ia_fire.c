/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** ia_fire
*/

#include <stdio.h>

#include "collectible.h"
#include "entity.h"
#include "particle.h"

static void drop_item(entity_t *entity)
{
    create_particle((sfVector3f){entity->x, entity->y, entity->z - 20},
        sfColor_fromRGB(255, 128, 0));
    drop_collectible(&get_current_room(get_run())->collectibles, entity->x,
        entity->y);
}

void ia_fire(entity_t *entity)
{
    if ((entity->life_time / 5 % 8) < 4)
        entity->spritesheet.current_step = (entity->life_time / 5 % 8);
    else
        entity->spritesheet.current_step = 8 - ((entity->life_time / 5 % 8));
    if (entity->life <= 0) {
        if (get_random(5) == 0)
            drop_item(entity);
        on_entity_death(entity);
        return;
    }
    update_animation(entity->sprite, &entity->spritesheet);
}
