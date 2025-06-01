/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** projectile_drawer
*/

#include <stdio.h>
#include <tgmath.h>
#include <SFML/Graphics/RenderWindow.h>

#include "list.h"
#include "raycaster.h"
#include "tear.h"
#include "wolf.h"

static void draw_tears(render_t *render)
{
    sfCircleShape *shape = sfCircleShape_create();
    list_t *tears = get_tears();
    tear_t *current;
    double current_radius;

    sfCircleShape_setTexture(shape, get_resource("tear_texture")->data,
        sfTrue);
    while (tears) {
        current = tears->data;
        current_radius = 15.0f / ((calculate_projected_distance(render,
            current->x, current->y, current->z) / TILE_SIZE) / 4);
        sfCircleShape_setRadius(shape, current_radius);
        sfCircleShape_setOrigin(shape, (sfVector2f)
            {current_radius / 2, current_radius / 2});
        sfCircleShape_setPosition(shape,
            project_point(render, current->x, current->y, current->z));
        sfRenderTexture_drawCircleShape(render->display->texture, shape, NULL);
        tears = tears->next;
    }
    sfCircleShape_destroy(shape);
}

void draw_projectiles(render_t *render)
{
    draw_tears(render);
}
