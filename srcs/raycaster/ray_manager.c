/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** ray_manager
*/

#include <stdlib.h>
#include <SFML/Graphics/RectangleShape.h>
#include "raycaster.h"
#include "wolf.h"

static display_t **local_get_display(void)
{
    static display_t *ray = NULL;

    return (&ray);
}

static void init_shader(display_t *display)
{
    display->shader.bright_shader =
        sfShader_createFromFile(NULL, NULL, "shaders/bloom_bright.frag");
    display->shader.combine_shader =
        sfShader_createFromFile(NULL, NULL, "shaders/bloom_combine.frag");
    display->shader.render_sprite = sfSprite_create();
    display->shader.render_texture = sfRenderTexture_create(get_window_width(),
        get_window_height(), sfFalse);
    sfShader_setFloatUniform(display->shader.bright_shader,
        "threshold", 1.0f);
    sfShader_setFloatUniform(display->shader.combine_shader,
        "bloomIntensity", 0.8f);
}

static void init_display_textures(display_t *display)
{
    sfTexture_setSmooth(display->texture_wall, sfFalse);
    sfTexture_setSmooth(display->texture_door, sfFalse);
    sfRectangleShape_setSize(display->final_shape,
        (sfVector2f) {get_window_width(), get_window_height()});
    sfVertexArray_resize(display->floor_array,
        get_window_width() * get_window_height());
    sfVertexArray_setPrimitiveType(display->floor_array, sfLineStrip);
    display->texture_scale = 1024;
    display->texture_scale_tiled = 1024 * TILE_SIZE_INV;
}

static void set_display_textures(display_t *dest)
{
    dest->texture_floor = get_resource("floor_texture")->data;
    dest->texture_wall = get_resource("wall_texture")->data;
    dest->texture_door = get_resource("door_texture")->data;
    dest->texture_door_item = get_resource("door_texture_item")->data;
    dest->texture_door_shop = get_resource("door_texture_shop")->data;
    dest->texture_door_boss = get_resource("door_texture_boss")->data;
}

void init_ray(void)
{
    display_t *display;

    display = malloc(sizeof(display_t));
    if (!display)
        return;
    display->wall = sfRectangleShape_create();
    display->texture = sfRenderTexture_create(get_window_width(),
        get_window_height(), sfFalse);
    display->final_shape = sfRectangleShape_create();
    display->shadow = sfRectangleShape_create();
    set_display_textures(display);
    display->floor_array = sfVertexArray_create();
    display->floor_image = sfTexture_copyToImage(display->texture_floor);
    display->floor_pixels_ptr = sfImage_getPixelsPtr(display->floor_image);
    init_display_textures(display);
    init_shader(display);
    *local_get_display() = display;
}

display_t *get_ray(void)
{
    return (*local_get_display());
}

void unload_ray(void)
{
    display_t *display;

    display = *local_get_display();
    if (!display)
        return;
    sfRectangleShape_destroy(display->shadow);
    sfRectangleShape_destroy(display->final_shape);
    sfRectangleShape_destroy(display->wall);
    sfShader_destroy(display->shader.bright_shader);
    sfShader_destroy(display->shader.combine_shader);
    sfSprite_destroy(display->shader.render_sprite);
    sfRenderTexture_destroy(display->shader.render_texture);
    sfVertexArray_destroy(display->floor_array);
    sfImage_destroy((sfImage *)display->floor_image);
    sfRenderTexture_destroy(display->texture);
    free(*local_get_display());
    *local_get_display() = NULL;
}
