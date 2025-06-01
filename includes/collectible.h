/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** collectible
*/

#ifndef COLLECTIBLE_H
    # define COLLECTIBLE_H
    # include "list.h"

typedef enum s_pickup_type {
    C_RED_HEART,
    C_HALF_RED_HEART,
    C_SOULD_HEART,
    C_ETERNAL_HEART,
    C_DOUBLE_HEART,
    C_BLACK_HEART,
    C_PENNY,
    C_NICKEL,
    C_DIME,
    C_DOUBLE_PENNY,
    C_BOMB,
    C_DOUBLE_BOMB,
    C_TROLL_BOMB,
    C_KEY,
    C_GOLDEN_KEY,
    C_KEY_RING,
    C_LIL_BATTERY,
    C_PILL_1,
    C_PILL_2,
    C_PILL_3,
    C_PILL_4,
    C_PILL_5,
    C_PILL_6,
    C_PILL_7,
    C_PILL_8,
    C_PILL_9
} pickup_type_t;

typedef struct s_pickup {
    char *display_name;
    char *resource_name;
    char *resource_path;
    pickup_type_t type;
    int (*pickup)();
    int shop_price;
    int chance_to_drop;
} collectible_t;

typedef struct s_dropped_collectible {
    const collectible_t *ref;
    double x;
    double y;
    double z;
} dropped_collectible_t;

void load_collectibles_resources(void);

collectible_t *get_collectible_by_type(pickup_type_t type);
const collectible_t *get_random_collectible(void);
void remove_dropped_pickup(dropped_collectible_t *dropped_pickup);

void pickup_collectible(dropped_collectible_t *dropped_collectible);
void drop_collectible(list_t **dest, double x, double y);

int on_red_heart_pickup(void);
int on_half_red_heart_pickup(void);

int on_penny_pickup(void);
int on_nickel_pickup(void);
int on_dime_pickup(void);

int on_bomb_pickup(void);
int on_double_bomb_pickup(void);

#endif
