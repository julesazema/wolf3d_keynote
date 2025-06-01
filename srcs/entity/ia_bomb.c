/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** ia_bomb
*/

#include <stdio.h>

#include "entity.h"
#include "item.h"
#include "particle.h"
#include "player.h"
#include "run.h"

static void damage_near_entities(entity_t *current)
{
    list_t *entities = get_current_room(get_run())->entities;
    entity_t *entity = NULL;

    while (entities) {
        entity = entities->data;
        if (entity != current && is_in_range(40, entity->x, current->x) &&
            is_in_range(40, entity->y, current->y)) {
            entity->life -= 20;
        }
        entities = entities->next;
    }
}

static void bomb_explosion(entity_t *entity)
{
    player_t *player = get_player();

    create_particle((sfVector3f){entity->x, entity->y, entity->z - 20},
            sfColor_fromRGB(255, 255, 255));
    create_particle((sfVector3f){entity->x, entity->y, entity->z - 20},
        sfColor_fromRGB(255, 255, 255));
    create_particle((sfVector3f){entity->x, entity->y, entity->z - 20},
        sfColor_fromRGB(255, 255, 255));
    if (is_in_range(80, entity->x, player->x) && is_in_range(80, entity->y,
        player->y))
        damage_player(get_player(), 1);
    damage_near_entities(entity);
    on_entity_death(entity);
}

void ia_bomb(entity_t *entity)
{
    create_clock("bomb_clock", 0.4f);
    create_clock("falling_bomb", 0.05f);
    if (entity->life <= 0)
        return (bomb_explosion(entity));
    scale_sprite(entity->sprite->name, 0.01f);
    if (entity->z > 20 && is_clock_elapsed("falling_bomb"))
        entity->velocity_z -= GRAVITY * 7;
    if (entity->z <= 20)
        entity->z = 20;
    if (is_clock_elapsed("bomb_clock") && entity->z <= 20) {
        entity->life -= 1;
        entity->damage_ticks = 5;
        create_particle((sfVector3f){entity->x, entity->y, entity->z - 20},
            sfColor_fromRGB(130, 130, 130));
    }
    update_animation(entity->sprite, &entity->spritesheet);
}
