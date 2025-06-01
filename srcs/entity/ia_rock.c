/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** ia_rock
*/

#include "collectible.h"
#include "entity.h"

static void drop_item(entity_t *entity)
{
    (void)entity;
    drop_collectible(&get_current_room(get_run())->collectibles,
        entity->x, entity->y);
}

void ia_rock(entity_t *entity)
{
    if (entity->life <= 0) {
        if (get_random(5) == 0)
            drop_item(entity);
        on_entity_death(entity);
    }
}
