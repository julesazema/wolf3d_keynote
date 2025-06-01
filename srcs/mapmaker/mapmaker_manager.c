/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** mapmaker_manager
*/

#include <stdlib.h>

#include "mapmaker.h"

mapmaker_t *init_mapmaker(void)
{
    mapmaker_t *result;

    result = malloc(sizeof(mapmaker_t));
    if (!result)
        return (NULL);
    result->run.nb_floors = 1;
    generate_floor(&result->run, 0);
    result->run.current_floor = 0;
    result->state = S_GLOBAL;
    return (result);
}
