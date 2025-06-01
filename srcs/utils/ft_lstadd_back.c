/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** ft_lstadd_back
*/

#include "wolf.h"
#include "list.h"

void ft_lstadd_back(list_t **lst, list_t *new)
{
    list_t *current;

    if (*lst == NULL) {
        *lst = new;
        return;
    }
    current = *lst;
    while (current->next)
        current = current->next;
    current->next = new;
}
