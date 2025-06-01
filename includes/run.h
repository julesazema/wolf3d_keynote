/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** run
*/

#ifndef RUN_H
    # define RUN_H

    # define MAX_FLOORS 13
    # define MAX_ROOMS 100
    # include "list.h"

typedef enum floor_type_s {
    THE_BASEMENT,
    THE_CELLAR,
    THE_BURNING_BASEMENT,
    THE_CAVES,
    THE_CATACOMBS,
    THE_FLOODED_CAVES,
    THE_DEPTHS,
    NECROPOLIS,
    DANK_DEPTHS,
    WOMB,
    UTERO,
    SCARRED_WOMB,
    SHEOL,
    CATHEDRAL,
    DARK_ROOM,
    THE_CHEST
} floor_type_t;

typedef enum room_type_s {
    CLASSIC_ROOM,
    ITEM_ROOM,
    BOSS_ROOM,
    MINIBOSS_ROOM,
    SHOP,
    SECRET_ROOM,
    SUPER_SECRET_ROOM,
    CURSE_ROOM,
    SACRIFICE_ROOM,
    CHALLENGE_ROOM,
    TRAP_ROOM,
    ARCADE,
    LIBRARY,
    DICE_ROOM
} room_type_t;

typedef struct room_s {
    room_type_t type;
    list_t *collectibles;
    list_t *items;
    list_t *entities;
    int id;
    int width;
    int height;
    int matrix[16][16];
    int floor_id;
    int floor_x;
    int floor_y;
    int finished;
    int visited;
} room_t;

typedef struct floor_s {
    floor_type_t type;
    room_t rooms[MAX_ROOMS];
    int nb_rooms;
    int floor_id;
} floor_t;

typedef struct run_s {
    int slot;
    int nb_floors;
    floor_t floors[MAX_FLOORS];
    int current_floor;
    int current_room;
} run_t;

run_t *get_run(void);
void set_run(run_t *run);

void generate_run(void);
void generate_floor(run_t *run, int floor_index);

room_t *create_unlinked_room(floor_t *floor, room_type_t type);

list_t *generate_room_collectibles(void);
list_t *generate_room_items(void);
room_t generate_room_content(room_type_t room_type, int index,
    int x, int y);
void generate_room_entities(room_t *dest);

room_t *get_room(floor_t *floor, int x, int y);
floor_t *get_current_floor(run_t *run);
room_t *get_current_room(run_t *run);
int count_links(floor_t *floor, int x, int y);

room_t *get_unlinked_room(floor_t *floor);

void generate_room_matrix(room_t *dest);

int contains_obstacle(double x, double y);
double get_dist_corner(double x, double y);
room_t *get_door_room(double x, double y);
int is_door(double x, double y);

int is_in_range(double size, double x, double x2);

void launch_run(void);
void launch_floor(int floor_index);
void launch_room(int room_index);

int load_run(void);
void save_run(run_t *run);

void unload_run(void);

#endif
