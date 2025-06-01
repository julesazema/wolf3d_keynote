/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** list
*/

#ifndef LIST_H
    # define LIST_H

typedef struct s_list {
    void *data;
    struct s_list *next;
} list_t;

void ft_lstadd_back(list_t **lst, list_t *new);
list_t *ft_createnode(void *data, list_t *next);
void free_node(list_t *node);

#endif
