/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** stats_manager
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stats.h"
#include "wolf.h"

static list_t **local_get_stats(void)
{
    static list_t *lines = NULL;

    return (&lines);
}

static stat_t *get_list_line(int index, list_t *name)
{
    list_t *list;
    int i = 0;

    list = name;
    while (i < index && list) {
        list = list->next;
        i++;
    }
    if (i == index && list)
        return (list->data);
    return (NULL);
}

void init_stat(stat_type_t name_type)
{
    stat_t *stats;

    stats = malloc(sizeof(stat_t));
    stats->type = name_type;
    stats->value = ft_strdup("0");
    ft_lstadd_back(local_get_stats(), ft_createnode(stats, NULL));
}

char *get_stat(stat_type_t type)
{
    int i = 0;

    while (get_list_line(i, *local_get_stats())) {
        if (get_list_line(i, *local_get_stats())->type == type)
            return get_list_line(i, *local_get_stats())->value;
        i++;
    }
    init_stat(type);
    return get_stat(type);
}

void add_stat(stat_type_t type)
{
    int i = 0;
    int value;

    get_stat(type);
    while (get_list_line(i, *local_get_stats()) != NULL) {
        if (get_list_line(i, *local_get_stats())->type == type) {
            value = ft_atoi(get_list_line(i, *local_get_stats())->value) + 1;
            free(get_list_line(i, *local_get_stats())->value);
            get_list_line(i, *local_get_stats())->value = ft_itoa(value);
            return;
        }
        i++;
    }
}

void add_stats_change_text(stat_type_t type, char *name_text)
{
    int i = 0;
    int value;

    get_stat(type);
    while (get_list_line(i, *local_get_stats()) != NULL) {
        if (get_list_line(i, *local_get_stats())->type == type) {
            value = ft_atoi(get_list_line(i, *local_get_stats())->value) + 1;
            free(get_list_line(i, *local_get_stats())->value);
            get_list_line(i, *local_get_stats())->value = ft_itoa(value);
            change_text(name_text,
                get_list_line(i, *local_get_stats())->value);
            return;
        }
        i++;
    }
}
