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

sfVector2f get_sprite_scale(entity_t *entity)
{
    sfVector2u texture_size;
    sfVector2f result;

    texture_size = sfTexture_getSize(entity->sprite->resource->data);
    result.x = (float) texture_size.x / entity->spritesheet.nb_cols;
    result.y = (float) texture_size.y / entity->spritesheet.nb_rows;
    result.x *= sfSprite_getScale(entity->sprite->sprite).x;
    result.y *= sfSprite_getScale(entity->sprite->sprite).y;
    result.x /= TILE_SIZE;
    result.y /= TILE_SIZE;
    return (result);
}

static void draw_hitbox(render_t *render, entity_t *entity)
{
    sfVertexArray *hitbox;
    sfVector2f scale = get_sprite_scale(entity);
    int x;
    int x2;
    int y;
    int y2;
    int z;
    int z2;

    printf("%6.1f // %6.1f\n", get_sprite_scale(entity).x, get_sprite_scale(entity).y);
    x = entity->x - scale.x / 2;
    x2 = entity->x + scale.x / 2;
    y = entity->y - scale.x / 2;
    y2 = entity->y + scale.x / 2;
    z = entity->z - scale.y / 2;
    z2 = entity->z + scale.y / 2;
    hitbox = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(hitbox, sfLineStrip);
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y, z2), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y, z2), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y, z2), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y2, z2), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y2, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y2, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y2, z2), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y, z2), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y2, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y2, z), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x, y2, z2), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y2, z2), sfRed, {0, 0}});
    sfVertexArray_append(hitbox, (sfVertex) {project_point(render, x2, y2, z), sfRed, {0, 0}});
    sfRenderTexture_drawVertexArray(render->display->texture, hitbox, NULL);
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
    draw_hitbox(render, entity);
    entity->ia(entity);
}

void display_entities(render_t *render)
{
    list_t *list;
    list_t *next;
    entity_t *current;
    room_t *current_room;
    int elapsed;

    create_clock("entity_lifetime", 0.001f);
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
