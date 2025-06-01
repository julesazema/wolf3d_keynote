/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** particle_manager
*/

#include <stdlib.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>
#include <stdio.h>

#include "list.h"
#include "particle.h"
#include "wolf.h"
#include "raycaster.h"

static list_t **local_get_particle(void)
{
    static list_t *list = NULL;

    return (&list);
}

static void set_particle_position(all_particle_t *particle, int i, sfVector3f
    position, sfColor color)
{
    particle->particles[i].elt.position.x = 0;
    particle->particles[i].elt.position.y = 0;
    particle->particles[i].position = position;
    particle->particles[i].elt.color = color;
    particle->particles[i].elt.position.x = particle->pos.x;
    particle->particles[i].elt.position.y = particle->pos.y;
}

void create_particle(sfVector3f position, sfColor color)
{
    all_particle_t *particle = malloc(sizeof(all_particle_t));

    if (!particle)
        return;
    particle->nb_particles = get_random(20) + 3;
    for (int i = 0; i < particle->nb_particles; i++) {
        set_particle_position(particle, i, position, color);
        particle->particles[i].velocity = (sfVector3f) {(float) get_random(
            100) / 100 * (get_random(2) == 0 ? -1.0f : 1.0f), (float)
            get_random(100) / 100 * (get_random(2) == 0 ? -1.0f : 1.0f),
            (float)get_random(100) / 100 * (get_random(2) == 0 ? -1.0f :
            1.0f)};
        particle->particles[i].life_time = 1.0f + ((float)get_random(100) /
            100);
        particle->particles[i].size = 1.0 + ((float)get_random(20) / 20);
    }
    particle->pos = position;
    *local_get_particle() = ft_createnode(particle, *local_get_particle());
}

static void set_particle_update(int i, all_particle_t *parts, float time)
{
    if (parts->particles[i].life_time <= 0)
        return;
    parts->particles[i].position.x += parts->particles[i].velocity.x;
    parts->particles[i].position.y += parts->particles[i].velocity.y;
    parts->particles[i].position.z += parts->particles[i].velocity.z;
    parts->particles[i].velocity.x /= 1.1;
    parts->particles[i].velocity.y /= 1.1;
    parts->particles[i].velocity.z /= 1.1;
    parts->particles[i].life_time -= time;
}

void update_particles(float time)
{
    list_t *list = *local_get_particle();
    all_particle_t *parts = NULL;

    while (list) {
        parts = list->data;
        for (int i = 0; i < parts->nb_particles; i++)
            set_particle_update(i, parts, time);
        list = list->next;
    }
}

static int is_particles_finished(all_particle_t *particle)
{
    for (int i = 0; i < particle->nb_particles; i++) {
        if (particle->particles[i].life_time > 0)
            return 0;
    }
    return 1;
}

static void draw_particle(all_particle_t *particle, sfRectangleShape *shape,
    render_t *render)
{
    particle_t *tmp;
    double radius;

    for (int i = 0; i < particle->nb_particles; i++) {
        tmp = &particle->particles[i];
        if (tmp->life_time <= 0)
            continue;
        tmp->elt.position = project_point(render,
            tmp->position.x, tmp->position.y, tmp->position.z);
        sfRectangleShape_setPosition(shape, tmp->elt.position);
        sfRectangleShape_setFillColor(shape, tmp->elt.color);
        radius = 30.0f / (calculate_projected_distance(render, tmp->position.x,
            tmp->position.y, tmp->position.y) / TILE_SIZE) / 4 * tmp->size;
        sfRectangleShape_setOutlineThickness(shape, (float)radius / 2);
        sfRectangleShape_setOutlineColor(shape,
            sfColor_modulate(tmp->elt.color, sfColor_fromRGB(60, 60, 60)));
        sfRectangleShape_setSize(shape, (sfVector2f) {radius, radius});
        sfRenderTexture_drawRectangleShape(render->display->texture, shape,
            NULL);
    }
}

static list_t *remove_particle(all_particle_t *particle, list_t *old,
    list_t *next, list_t *list)
{
    list_t **head = local_get_particle();

    if (is_particles_finished(particle)) {
        if (old)
            old->next = next;
        else
            *head = next;
        free(list->data);
        free(list);
    } else {
        old = list;
    }
    return old;
}

void draw_particles(render_t *render)
{
    list_t *list = *local_get_particle();
    all_particle_t *particle = NULL;
    list_t *old = NULL;
    list_t *next;
    sfRectangleShape *shape;

    if (!list)
        return;
    shape = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    while (list) {
        next = list->next;
        particle = list->data;
        draw_particle(particle, shape, render);
        old = remove_particle(particle, old, next, list);
        list = next;
    }
    sfRectangleShape_destroy(shape);
}
