/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** spritesheet
*/

#ifndef SPRITESHEET_H
    # define SPRITESHEET_H

    # include "wolf.h"

typedef struct s_spritesheet {
    char resource_name[256];
    int nb_cols;
    int nb_rows;
    int nb_steps;
    int current_step;
} spritesheet_t;

spritesheet_t create_spritesheet(char *resource_name,
    int nb_cols, int nb_rows, int nb_steps);
void update_animation(sprite_t *sprite, spritesheet_t *spritesheet);

#endif
