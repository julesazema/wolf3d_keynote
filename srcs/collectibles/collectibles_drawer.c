/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** items_displayer
*/

#include "collectible.h"
#include "raycaster.h"
#include "run.h"
#include "wolf.h"

static void draw_collectible(pickup_type_t type,
    render_t *render, sfVector3f location)
{
    sfCircleShape *shape = sfCircleShape_create();
    double current_radius;
    double z = 0.35f + location.z;

    sfCircleShape_setTexture(shape,
        get_resource(get_collectible_by_type(type)->resource_name)->data,
        sfTrue);
    current_radius = 30.0f / ((calculate_projected_distance(render,
        location.x,
        location.y, z)) / 8) * 20;
    sfCircleShape_setRadius(shape, current_radius);
    sfCircleShape_setOrigin(shape,
        (sfVector2f) {current_radius / 2, current_radius / 2});
    sfCircleShape_setPosition(shape, project_point(render,
        location.x, location.y, z));
    sfRenderTexture_drawCircleShape(render->display->texture, shape, NULL);
    sfCircleShape_destroy(shape);
}

static void display_price(room_t *room, dropped_collectible_t *tmp, render_t
    *render)
{
    if (room->type == SHOP)
        project_text(tmp->ref->display_name, (sfVector3f) {tmp->x, tmp->y,
        tmp->z - 8}, render);
}

void draw_collectibles(render_t *render)
{
    room_t *room;
    list_t *list;
    dropped_collectible_t *tmp;
    char price_txt[16];

    room = get_current_room(get_run());
    list = room->collectibles;
    while (list) {
        tmp = list->data;
        draw_collectible(tmp->ref->type,
            render, (sfVector3f) {tmp->x, tmp->y, tmp->z * 0.001f - 0.2f});
        ft_itoad(tmp->ref->shop_price, price_txt, 16);
        ft_strcpy(price_txt + ft_strlen(price_txt), "$");
        create_text(tmp->ref->display_name, price_txt, "font");
        colorize_text(tmp->ref->display_name, sfWhite);
        scale_text(tmp->ref->display_name, 60);
        display_price(room, tmp, render);
        list = list->next;
    }
}
