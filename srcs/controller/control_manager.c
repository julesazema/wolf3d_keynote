/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** control_manager
*/

#include <stdlib.h>

#include "option.h"

static control_t ***local_get_control(void)
{
    static control_t **control = NULL;

    return (&control);
}

control_t **get_control(void)
{
    return (*local_get_control());
}

static void init_control_player(control_t **control)
{
    control[K_MOVE_FORWARD]->key = K_MOVE_FORWARD;
    control[K_MOVE_FORWARD]->name = get_name_control(sfKeyZ);
    control[K_MOVE_FORWARD]->description = "FORWARD";
    control[K_MOVE_FORWARD]->code = sfKeyZ;
    control[K_MOVE_BACKWARD]->key = K_MOVE_BACKWARD;
    control[K_MOVE_BACKWARD]->name = get_name_control(sfKeyS);
    control[K_MOVE_BACKWARD]->description = "BACKWARD";
    control[K_MOVE_BACKWARD]->code = sfKeyS;
    control[K_MOVE_LEFT]->key = K_MOVE_LEFT;
    control[K_MOVE_LEFT]->name = get_name_control(sfKeyQ);
    control[K_MOVE_LEFT]->description = "LEFT";
    control[K_MOVE_LEFT]->code = sfKeyQ;
    control[K_MOVE_RIGHT]->key = K_MOVE_RIGHT;
    control[K_MOVE_RIGHT]->name = get_name_control(sfKeyD);
    control[K_MOVE_RIGHT]->description = "RIGHT";
    control[K_MOVE_RIGHT]->code = sfKeyD;
    control[K_PLACEBOMB]->key = K_PLACEBOMB;
    control[K_PLACEBOMB]->name = get_name_control(sfKeyC);
    control[K_PLACEBOMB]->description = "PLACE BOMB";
    control[K_PLACEBOMB]->code = sfKeyC;
}

void init_control(void)
{
    control_t **control = malloc(sizeof(control_t *) * (NBR_CTRL + 1));

    if (!control)
        return;
    for (int i = 0; i < NBR_CTRL; i++)
        control[i] = malloc(sizeof(control_t));
    control[K_JUMP]->key = K_JUMP;
    control[K_JUMP]->name = get_name_control(sfKeySpace);
    control[K_JUMP]->description = "JUMP";
    control[K_JUMP]->code = sfKeySpace;
    init_control_player(control);
    control[NBR_CTRL] = NULL;
    *local_get_control() = control;
}

void unload_control(void)
{
    for (int i = 0; i < NBR_CTRL; i++)
        free(get_control()[i]);
    free(get_control());
}
