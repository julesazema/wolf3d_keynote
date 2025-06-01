/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** bloom_shader
*/

#include "raycaster.h"
#include "wolf.h"

void render_shaders(render_t *render, sfRenderTexture *scene_rt)
{
    sfSprite_setTexture(render->display->shader.render_sprite,
        sfRenderTexture_getTexture(scene_rt), sfTrue);
    sfRenderTexture_clear(render->display->shader.render_texture, sfBlack);
    sfShader_bind(render->display->shader.bright_shader);
    sfRenderTexture_drawSprite(render->display->shader.render_texture,
        render->display->shader.render_sprite, NULL);
    sfRenderTexture_display(render->display->shader.render_texture);
    sfShader_bind(NULL);
    sfShader_setTextureUniform(render->display->shader.combine_shader,
        "sceneTexture", sfRenderTexture_getTexture(scene_rt));
    sfSprite_setTexture(render->display->shader.render_sprite,
        sfRenderTexture_getTexture(scene_rt), sfTrue);
    sfShader_bind(render->display->shader.combine_shader);
    sfRenderWindow_drawSprite(get_window(),
        render->display->shader.render_sprite, NULL);
    sfShader_bind(NULL);
}
