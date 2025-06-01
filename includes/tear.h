/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** tear
*/

#ifndef TEAR_H
    # define TEAR_H

    # include "list.h"
    # include "player.h"
    # include "raycaster.h"

typedef struct tear_s {
    double x;
    double y;
    double z;
    double vector_x;
    double vector_y;
    double vector_z;
} tear_t;

void launch_tear(player_t *player);
list_t *get_tears(void);
void remove_tear(tear_t *tear);
int is_tear(int x, int y);

void draw_projectiles(render_t *render);
void handle_projectiles_movements(void);

#endif
