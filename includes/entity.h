/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity
*/

#ifndef ENTITY_H
    # define ENTITY_H

    # include "list.h"
    # include "run.h"
    # include "spritesheet.h"
    # include "wolf.h"

typedef enum s_entity_type {
    E_EMBRYO,
    E_BLOB,
    E_LOKI,
    E_FATTY,
    E_FLY,
    E_KING_FLY,
    E_CACA,
    E_RED_FLY,
    E_ROCK,
    E_FIRE,
    E_BLUEFIRE,
    E_BOMB,
    E_LADDER,
} entity_type_t;

typedef struct s_entity {
    sprite_t *sprite;
    spritesheet_t spritesheet;
    entity_type_t type;
    void (*ia)(struct s_entity *);
    double x;
    double y;
    double z;
    double velocity_x;
    double velocity_y;
    double velocity_z;
    int floor_id;
    int room_id;
    int max_life;
    int life;
    int damage_ticks;
    int life_time;
} entity_t;

typedef struct s_entity_model {
    entity_type_t type;
    int life;
    char *resource_name;
    int nb_cols;
    int nb_rows;
    int nb_steps;
    void (*ia)(entity_t *);
} entity_model_t;

entity_t *create_entity(room_t *room, entity_type_t type, sfVector3f location);

list_t *get_entities(void);

const entity_model_t *get_entity_model(entity_type_t entity_type);
spritesheet_t model_to_spritesheet(const entity_model_t *model);

int is_entity_outside_room(entity_t *entity);

void on_entity_death(entity_t *entity);

sfVector2f get_sprite_scale(entity_t *entity);

void ia_slime(entity_t *);
void ia_blob(entity_t *);
void ia_loki(entity_t *);
void ia_fatty(entity_t *);
void ia_fly(entity_t *);
void ia_red_fly(entity_t *);
void ia_king_fly(entity_t *);
void ia_caca(entity_t *);
void ia_fire(entity_t *);
void ia_bluefire(entity_t *);
void ia_rock(entity_t *);
void ia_bomb(entity_t *);
void ia_ladder(entity_t *);

#endif
