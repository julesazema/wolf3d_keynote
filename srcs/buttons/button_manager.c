/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** button_manager
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#include "wolf.h"

static list_t **local_get_buttons(void)
{
    static list_t *buttons = NULL;

    return (&buttons);
}

static sfSprite *init_button_sprite(int x, int y, resource_t *resource)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, (sfVector2f){x, y});
    sfSprite_setTexture(sprite, resource->data, sfTrue);
    return (sprite);
}

void create_button(char *resource_name, int x, int y,
    void (*on_click) (void))
{
    button_t *result;
    resource_t *resource = get_resource(resource_name);

    if (resource == NULL || resource->type != TEXTURE)
        return;
    result = malloc(sizeof(button_t));
    if (!result)
        return;
    ft_strcpy(result->name, resource_name);
    result->state = IDLE;
    result->on_click = on_click;
    result->sprite = init_button_sprite(x, y, resource);
    result->hidden = 0;
    result->texture = resource;
    *local_get_buttons() = ft_createnode(result, *local_get_buttons());
}

button_t *get_button(char *name)
{
    list_t *current;

    current = *local_get_buttons();
    while (current) {
        if (ft_strcmp(((button_t *)current->data)->name, name) == 0)
            return (current->data);
        current = current->next;
    }
    return (NULL);
}

void update_buttons(int mouse_x, int mouse_y, int state)
{
    list_t *list = *local_get_buttons();
    button_t *current;
    int in_range;

    while (list) {
        current = list->data;
        in_range = is_mouse_inrange(sfSprite_getGlobalBounds(current->sprite),
            mouse_x, mouse_y);
        if (in_range && state && !current->hidden) {
            current->state = CLICKED;
            current->on_click();
            play_sound_pitched("select_low", 0.6f);
            break;
        }
        if (in_range && !state && !current->hidden)
            current->state = HOVER;
        if (!in_range && !current->hidden)
            current->state = IDLE;
        list = list->next;
    }
}

void unload_buttons(void)
{
    list_t *current;
    list_t *next;

    current = *local_get_buttons();
    while (current) {
        next = current->next;
        sfSprite_destroy(((button_t *) current->data)->sprite);
        free(current->data);
        free(current);
        current = next;
    }
}
