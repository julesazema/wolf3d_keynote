/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** items_displayer
*/

#include "item.h"
#include "raycaster.h"
#include "run.h"
#include "wolf.h"

static void draw_pedestral(render_t *render, double item_x, double item_y)
{
    sfCircleShape *shape = sfCircleShape_create();
    double current_radius;
    double z = 10;

    sfCircleShape_setTexture(shape, get_resource("pedestral")->data, sfTrue);
    current_radius = 30.0f / ((calculate_projected_distance(render, item_x,
        item_y, z)) / 8) * 50;
    sfCircleShape_setRadius(shape, current_radius);
    sfCircleShape_setOrigin(shape,
        (sfVector2f) {current_radius / 2, current_radius / 2});
    sfCircleShape_setPosition(shape, project_point(render,
        item_x, item_y, z));
    sfRenderTexture_drawCircleShape(render->display->texture, shape, NULL);
    sfCircleShape_destroy(shape);
}

static void draw_item(item_type_t type, render_t *render, sfVector3f location)
{
    sfCircleShape *shape = sfCircleShape_create();
    double current_radius;

    load_resource(get_item_by_type(type)->display_name,
        get_item_by_type(type)->resource_name, TEXTURE);
    sfCircleShape_setTexture(shape,
        get_resource(get_item_by_type(type)->display_name)->data, sfTrue);
    current_radius = 30.0f / ((calculate_projected_distance(render,
        location.x, location.y, location.z)) / 8) * 50;
    sfCircleShape_setRadius(shape, current_radius);
    sfCircleShape_setOrigin(shape,
        (sfVector2f) {current_radius / 2, current_radius / 2});
    sfCircleShape_setPosition(shape, project_point(render,
        location.x, location.y, location.z));
    sfRenderTexture_drawCircleShape(render->display->texture, shape, NULL);
    sfCircleShape_destroy(shape);
}

static int translate_animation(int animation)
{
    if (animation > 15)
        animation = 30 - animation;
    if (animation > 12)
        animation = 12 + ((15 - animation) / 2);
    if (animation < 3)
        animation = 3 - (animation / 2);
    return (animation);
}

void draw_items(render_t *render)
{
    static int animation = 0;
    list_t *list;
    dropped_item_t *tmp;

    list = get_current_room(get_run())->items;
    if (!list)
        return;
    if (is_clock_elapsed("pedestral_animation"))
        animation++;
    if (animation >= 30)
        animation = 0;
    while (list) {
        tmp = list->data;
        draw_pedestral(render, tmp->x, tmp->y);
        draw_item(tmp->ref->type, render, (sfVector3f) {tmp->x, tmp->y,
            22.0f + tmp->z + (float)translate_animation(animation) / 8});
        list = list->next;
    }
}
