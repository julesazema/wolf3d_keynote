/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** mapmaker
*/

#ifndef MAPMAKER_H
    # define MAPMAKER_H

    # include "run.h"

typedef enum mapmaker_state_s {
    S_GLOBAL,
    S_EDITFLOOR,
    S_EDITROOM
} mapmaker_state_t;

typedef struct s_mapmaker {
    run_t run;
    mapmaker_state_t state;
} mapmaker_t;

mapmaker_t *init_mapmaker(void);

#endif
