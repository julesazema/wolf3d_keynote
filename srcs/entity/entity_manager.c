/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_manager
*/

#include <stdio.h>
#include <stdlib.h>

#include "entity.h"
#include "list.h"

static void setup_entity_sprite(entity_t *dest, spritesheet_t sheet)
{
    sfVector2u size;
    char name[16];

    dest->spritesheet = sheet;
    dest->sprite = create_sprite(ft_itoad(get_random(4096 * 2),
        name, 16), 0, 0, sheet.resource_name);
    size = sfTexture_getSize(dest->sprite->resource->data);
    sfSprite_setOrigin(dest->sprite->sprite, (sfVector2f) {size.x / 2, size.y});
}

static void setup_entity(entity_t *entity, const entity_model_t *model,
    sfVector3f location)
{
    entity->x = location.x;
    entity->y = location.y;
    entity->z = location.z;
    entity->velocity_x = 0;
    entity->velocity_y = 0;
    entity->velocity_z = 0;
    entity->max_life = model->life;
    entity->life = entity->max_life;
    entity->ia = model->ia;
    entity->damage_ticks = 0;
    entity->life_time = 0;
}

entity_t *create_entity(room_t *room, entity_type_t type, sfVector3f location)
{
    const entity_model_t *model = get_entity_model(type);
    entity_t *entity = malloc(sizeof(entity_t));

    if (!entity)
        return (NULL);
    if (!model)
        return (free(entity), NULL);
    room->finished = 0;
    entity->room_id = room->id;
    entity->floor_id = room->floor_id;
    entity->type = type;
    setup_entity(entity, model, location);
    setup_entity_sprite(entity, model_to_spritesheet(model));
    ft_lstadd_back(&room->entities, ft_createnode(entity, NULL));
    return (entity);
}
