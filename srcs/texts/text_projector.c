/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** text_projector
*/

#include <stdio.h>

#include "wolf.h"
#include "raycaster.h"

static void set_rect_price(sfRectangleShape *rect, text_t *text, float size,
    sfVector2f new_position)
{
    float size_x;
    float size_y;

    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(10, 10,
        10, 150));
    size_x = sfText_getLocalBounds(text->text).width * size * 1.2;
    size_y = sfText_getLocalBounds(text->text).height * size * 1.9;
    sfRectangleShape_setSize(rect, (sfVector2f) {size_x, size_y});
    sfRectangleShape_setOrigin(rect, (sfVector2f) {size_x / 2, size_y / 2});
    sfRectangleShape_setPosition(rect, (sfVector2f) {new_position.x,
        new_position.y + size_y / 2});
}

void project_text(char *text_name, sfVector3f position, render_t *render)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    text_t *text;
    sfVector2f new_position = project_point(render, position.x, position.y,
        position.z);
    float size = 80.0f / calculate_projected_distance(render, position.x,
        position.y, position.z);

    text = get_text(text_name);
    if (!text)
        return;
    if (size < 0)
        return;
    set_rect_price(rect, text, size, new_position);
    sfText_setScale(text->text, (sfVector2f) {size, size});
    center_text_origin(text_name);
    move_text(text_name, new_position.x, new_position.y);
    sfRenderTexture_drawRectangleShape(render->display->texture, rect, NULL);
    sfRenderTexture_drawText(render->display->texture, text->text, NULL);
    sfRectangleShape_destroy(rect);
}
