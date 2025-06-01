/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_displayer
*/

#include <stdio.h>

#include "entity.h"
#include "raycaster.h"

void clamp_position(entity_t *entity)
{
    room_t *room;

    room = &get_run()->floors[entity->floor_id].rooms[entity->room_id];
    if (entity->x < 0.0f)
        entity->x = 0;
    if (entity->y < 0.0f)
        entity->y = 0;
    if (entity->x > room->width * TILE_SIZE)
        entity->x = room->width * TILE_SIZE;
    if (entity->y > room->height * TILE_SIZE)
        entity->y = room->height * TILE_SIZE;
}

static void entity_routine(entity_t *entity)
{
    if (entity->damage_ticks == 0)
        sfSprite_setColor(entity->sprite->sprite, sfWhite);
    else {
        sfSprite_setColor(entity->sprite->sprite, sfRed);
        entity->damage_ticks--;
    }
    clamp_position(entity);
}

static void update_entity_velocity(entity_t *entity)
{
    entity->x += entity->velocity_x;
    entity->y += entity->velocity_y;
    entity->z += entity->velocity_z;
    entity->velocity_x /= 2;
    entity->velocity_y /= 2;
    entity->velocity_z /= 2;
}

static void draw_entity(render_t *render, entity_t *entity)
{
    sprite_t *sprite;
    double current_radius;
    sfVector2f projected_point;

    update_entity_velocity(entity);
    entity_routine(entity);
    sprite = entity->sprite;
    projected_point = project_point(render, entity->x, entity->y, entity->z);
    current_radius = 30.0f / ((calculate_projected_distance(render,
        entity->x, entity->y, entity->z)) / 8) * 150;
    center_sprite(sprite->name, projected_point.x, projected_point.y);
    rescale_sprite(sprite->name, (float)current_radius / 80);
    sfRenderTexture_drawSprite(render->display->texture, sprite->sprite, NULL);
    entity->ia(entity);
}

void display_entities(render_t *render)
{
    list_t *list;
    list_t *next;
    entity_t *current;
    room_t *current_room;
    int elapsed;

    create_clock("entity_lifetime", 0.1f);
    elapsed = is_clock_elapsed("entity_lifetime");
    current_room = get_current_room(get_run());
    list = current_room->entities;
    while (list) {
        next = list->next;
        current = list->data;
        if (elapsed)
            current->life_time += 1;
        draw_entity(render, current);
        list = next;
    }
}
