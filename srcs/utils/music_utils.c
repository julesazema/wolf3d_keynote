/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** music_utils
*/

#include "option.h"
#include "wolf.h"

void play_music(char *resource_name)
{
    resource_t *resource;

    resource = get_resource(resource_name);
    if (!resource || resource->type != MUSIC)
        return;
    sfMusic_setLoop(resource->data, sfTrue);
    sfMusic_play(resource->data);
}

int get_music_status(char *resource_name)
{
    resource_t *resource;

    resource = get_resource(resource_name);
    if (!resource || resource->type != MUSIC)
        return (0);
    return (sfMusic_getStatus(resource->data));
}

void set_music_playing_offset(char *resource_name, double offset)
{
    resource_t *resource;

    resource = get_resource(resource_name);
    if (!resource || resource->type != MUSIC)
        return;
    sfMusic_setPlayingOffset(resource->data, (sfTime) {offset * 1000000});
}

void set_music_volume(char *resource_name, float volume)
{
    resource_t *resource;

    resource = get_resource(resource_name);
    if (!resource || resource->type != MUSIC)
        return;
    sfMusic_setVolume(resource->data, volume * (get_option()->music * 10));
}

void stop_music(char *resource_name)
{
    resource_t *resource;

    resource = get_resource(resource_name);
    if (!resource || resource->type != MUSIC)
        return;
    sfMusic_pause(resource->data);
}
