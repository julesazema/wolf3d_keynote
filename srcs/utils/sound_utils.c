/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** sound_utils
*/

#include "option.h"
#include "wolf.h"

void play_sound(char *resource_name)
{
    play_sound_pitched(resource_name, 1);
}

void play_sound_pitched(char *resource_name, float pitch)
{
    resource_t *resource;

    resource = get_resource(resource_name);
    if (!resource || resource->type != SOUND)
        return;
    sfSound_setPitch(resource->data, pitch);
    sfSound_setVolume(resource->data, get_option()->sound * 10);
    sfSound_play(resource->data);
}
