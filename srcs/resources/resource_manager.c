/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** resource_manager
*/

#include "stdlib.h"
#include "wolf.h"
#include "list.h"

static list_t **local_get_resources(void)
{
    static list_t *resources = NULL;

    return (&resources);
}

static void destroy_sound(resource_t *resource)
{
    sfSound *sound;
    sfSoundBuffer *sound_buffer;

    if (resource->type != SOUND)
        return;
    sound = resource->data;
    sound_buffer = (sfSoundBuffer *) sfSound_getBuffer(sound);
    sfSound_destroy(sound);
    sfSoundBuffer_destroy(sound_buffer);
}

static resource_t *load_texture(char *path)
{
    resource_t *result;
    sfTexture *texture;

    result = malloc(sizeof(resource_t));
    if (!result)
        return (NULL);
    texture = sfTexture_createFromFile(path, NULL);
    if (!texture) {
        free(result);
        return (NULL);
    }
    result->data = texture;
    return (result);
}

static resource_t *load_sound(char *path)
{
    resource_t *result;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;

    result = malloc(sizeof(resource_t));
    if (!result)
        return (NULL);
    sound_buffer = sfSoundBuffer_createFromFile(path);
    if (!sound_buffer) {
        free(result);
        return (NULL);
    }
    sound = sfSound_create();
    sfSound_setBuffer(sound, sound_buffer);
    sfSound_setAttenuation(sound, 0.0f);
    result->data = sound;
    return (result);
}

static resource_t *load_music(char *path)
{
    resource_t *result;
    sfMusic *music;

    result = malloc(sizeof(resource_t));
    if (!result)
        return (NULL);
    music = sfMusic_createFromFile(path);
    if (!music) {
        free(result);
        return (NULL);
    }
    result->data = music;
    return (result);
}

static resource_t *load_font(char *path)
{
    resource_t *result;
    sfFont *font;

    result = malloc(sizeof(resource_t));
    if (!result)
        return (NULL);
    font = sfFont_createFromFile(path);
    if (!font) {
        free(result);
        return (NULL);
    }
    result->data = font;
    return (result);
}

void load_resource(char *name, char *path, resource_type_t type)
{
    resource_t *resource = NULL;

    if (!exists_file(path)) {
        ft_putstr_fd(2, path);
        ft_putstr_fd(2, ": resource missing.\n");
        return;
    }
    if (type == TEXTURE)
        resource = load_texture(path);
    if (type == SOUND)
        resource = load_sound(path);
    if (type == MUSIC)
        resource = load_music(path);
    if (type == FONT)
        resource = load_font(path);
    if (!resource)
        return;
    resource->type = type;
    ft_strcpy(resource->name, name);
    *local_get_resources() = ft_createnode(resource, *local_get_resources());
}

resource_t *get_resource(char *name)
{
    list_t *current;

    current = *local_get_resources();
    while (current) {
        if (ft_strcmp(((resource_t *)current->data)->name, name) == 0)
            return (current->data);
        current = current->next;
    }
    return (NULL);
}

void unload_resources(void)
{
    list_t *current = *local_get_resources();
    list_t *next;
    resource_t *current_resource;

    while (current) {
        current_resource = current->data;
        next = current->next;
        if (current_resource->type == TEXTURE)
            sfTexture_destroy(current_resource->data);
        if (current_resource->type == SOUND)
            destroy_sound(current_resource);
        if (current_resource->type == FONT)
            sfFont_destroy(current_resource->data);
        if (current_resource->type == MUSIC)
            sfMusic_destroy(current_resource->data);
        free(current_resource);
        free(current);
        current = next;
    }
    *local_get_resources() = NULL;
}
