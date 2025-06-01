/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** stats
*/

#ifndef STAT_H
    # define STAT_H

typedef enum {
    TIME,
    KILL,
    DEAD,
    NB_GAME,
} stat_type_t;

typedef struct s_stat {
    stat_type_t type;
    char *value;
} stat_t;

void init_stat(stat_type_t name_type);
char *get_stat(stat_type_t type);
void add_stat(stat_type_t type);

void add_stats_change_text(stat_type_t type, char *name_text);

#endif
