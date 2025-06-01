/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** item
*/

#ifndef ITEM_H
    # define ITEM_H

typedef enum s_item_type {
    I_HEART,
    I_BLUEHEART,
    I_TOOTHPICKS,
    I_SYNTHOIL,
    I_PYJAMAS,
    I_CRICKETS_HEAD,
    I_DOLLAR,
    I_BOOM,
    I_ODD_MUSHROOM,
    I_CAT_O_NINE_TAILS,
    I_NUMBER_ONE,
    I_POLYPHEMUS,
    I_SAD_ONION,
    I_A_QUARTER,
    I_SMALL_ROCK,
    I_PYROMANIA,
    I_ROSARY
} item_type_t;

typedef struct s_item {
    char *display_name;
    char *resource_name;
    char *description;
    item_type_t type;
    void (*pickup)();
    int chance_to_drop;
} item_t;

typedef struct s_dropped_item {
    const item_t *ref;
    double x;
    double y;
    double z;
} dropped_item_t;

const item_t *get_item_by_type(item_type_t type);
const item_t *get_random_item(void);

void remove_dropped_item(dropped_item_t *dropped_item);

void pickup_item(dropped_item_t *item);
int has_item(item_type_t type);

void on_heart_pickup(void);
void on_sinthoil_pickup(void);
void on_crickets_head_pickup(void);
void on_toothpick_pickup(void);
void on_dollar_pickup(void);
void on_boom_pickup(void);
void on_odd_mushroom_pickup(void);
void on_cat_o_nine_tails_pickup(void);
void on_number_one_pickup(void);
void on_polyphemus_pickup(void);
void on_sad_onion_pickup(void);
void on_a_quarter_pickup(void);
void on_small_rock_pickup(void);
void on_pyromania_pickup(void);
void on_rosary_pickup(void);

#endif
