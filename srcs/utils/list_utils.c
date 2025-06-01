/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** list_utils
*/

#include <stdlib.h>
#include "list.h"
#include "wolf.h"

list_t *ft_createnode(void *data, list_t *next)
{
    list_t *result;

    result = malloc(sizeof(list_t));
    if (!result)
        return (next);
    result->data = data;
    result->next = next;
    return (result);
}

void free_node(list_t *node)
{
    free(node->data);
    free(node);
}
