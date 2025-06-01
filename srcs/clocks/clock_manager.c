/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** clock_manager
*/

#include <stdlib.h>
#include "list.h"
#include "wolf.h"

static list_t **local_get_clocks(void)
{
    static list_t *clocks = NULL;

    return (&clocks);
}

void create_clock(char *name, float time_repeat)
{
    runnable_t *result;

    if (get_clock(name) != NULL)
        return;
    result = malloc(sizeof(runnable_t));
    if (!result)
        return;
    ft_strcpy(result->name, name);
    result->time_repeat = time_repeat;
    result->clock = sfClock_create();
    *local_get_clocks() = ft_createnode(result, *local_get_clocks());
}

runnable_t *get_clock(char *name)
{
    list_t *list;
    runnable_t *current;

    list = *local_get_clocks();
    while (list) {
        current = list->data;
        if (ft_strcmp(current->name, name) == 0)
            return (current);
        list = list->next;
    }
    return (NULL);
}

void unload_clocks(void)
{
    list_t *list;
    list_t *next;
    runnable_t *current;

    list = *local_get_clocks();
    while (list) {
        current = list->data;
        next = list->next;
        sfClock_destroy(current->clock);
        free(current->name);
        free(list);
        list = next;
    }
}
