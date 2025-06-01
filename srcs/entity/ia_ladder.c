/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** ia_ladder
*/

#include <stdio.h>

#include "entity.h"
#include "player.h"

void ia_ladder(entity_t *entity)
{
    if (entity->life <= 0)
        return on_entity_death(entity);
    if (is_in_range(20, entity->x, get_player()->x) && is_in_range(20,
        entity->y, get_player()->y)) {
        entity->life = 0;
        get_run()->nb_floors++;
        generate_floor(get_run(), get_run()->nb_floors - 1);
        get_run()->current_floor++;
        get_run()->current_room = 0;
    }
}
