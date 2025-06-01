/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** actionbar_manager
*/

#include <stdlib.h>

#include "wolf.h"
#include "list.h"
#include "actionbar.h"

static list_t **local_get_actionbars(void)
{
    static list_t *actionbars = NULL;

    return (&actionbars);
}

actionbar_t *get_top_action(void)
{
    if (*local_get_actionbars())
        return ((*local_get_actionbars())->data);
    return (NULL);
}

void display_action(char *content, double time_display)
{
    actionbar_t *result;

    result = malloc(sizeof(actionbar_t));
    if (!result)
        return;
    ft_strcpy(result->content, content);
    result->subtitle[0] = 0;
    result->max_time = time_display;
    result->displayed_time = 0;
    result->launched = 0;
    ft_lstadd_back(local_get_actionbars(), ft_createnode(result, NULL));
}

void display_title(char *title, char *subtitle, double time_display)
{
    actionbar_t *result;

    result = malloc(sizeof(actionbar_t));
    if (!result)
        return;
    ft_strcpy(result->content, title);
    ft_strcpy(result->subtitle, subtitle);
    result->max_time = time_display;
    result->displayed_time = 0;
    result->launched = 0;
    ft_lstadd_back(local_get_actionbars(), ft_createnode(result, NULL));
}

void remove_actionbar(actionbar_t *actionbar)
{
    list_t *list;
    list_t *next;

    list = *local_get_actionbars();
    if (list->data == actionbar) {
        *local_get_actionbars() = list->next;
        free(list->data);
        free(list);
        return;
    }
    while (list && list->next) {
        if (list->next->data == actionbar) {
            next = list->next->next;
            free(list->next->data);
            free(list->next);
            list->next = next;
            continue;
        }
        list = list->next;
    }
}
