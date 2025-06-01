/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** particle
*/

#ifndef PARTICLE_H
    # define PARTICLE_H

    #include <SFML/Graphics/Vertex.h>

    #define MAX_PARTICLE 1000

typedef struct particle_s {
    sfVertex elt;
    sfVector3f velocity;
    sfVector3f position;
    double size;
    double life_time;
} particle_t;

typedef struct all_particle_s {
    particle_t particles[MAX_PARTICLE];
    int nb_particles;
    sfVector3f pos;
    int current_particle;
} all_particle_t;

void init_particle(void);

void create_particle(sfVector3f pos, sfColor color);
void update_particles(float time);

#endif
