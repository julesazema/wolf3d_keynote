/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** ia_bluefire
*/

#include "entity.h"

static void drop_item(entity_t *entity)
{
    (void)entity;
}

void ia_bluefire(entity_t *entity)
{
    if (entity->life <= 0) {
        if (get_random(2) == 0)
            drop_item(entity);
        on_entity_death(entity);
        return;
    }
    update_animation(entity->sprite, &entity->spritesheet);
    (void)entity;
}
