/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player
*/

#ifndef PLAYER_H
    # define PLAYER_H

    # define NUM_RAYS 1280
    # define TILE_SIZE 64
    # define TILE_SIZE_INV (1.0f / TILE_SIZE)
    # define TILE_SIZE_DELTA (0.01f * TILE_SIZE)
    # define FOV 70

    # define GRAVITY 0.55

    # include "list.h"

typedef enum s_player_action {
    JUMP,
    SHOOT,
    PLACE_BOMB
} player_action_t;

typedef struct s_playerstat {
    double speed;
    double attack_speed;
    double damages;
    double shoot_range;
    double tears_speed;
    double chance;
    double devil_deal;
    double angel_deal;
} playerstat_t;

typedef struct s_inventory {
    list_t *items;
    int coins;
    int bombs;
    int keys;
} inventory_t;

typedef struct s_player {
    inventory_t inventory;
    playerstat_t stats;
    double x;
    double y;
    double z;
    double yaw;
    double pitch;
    double velocity_x;
    double velocity_y;
    double velocity_z;
    int life;
    int max_life;
    int blue_hearth;
} player_t;

void init_player(void);
player_t *get_player(void);
void unload_player(void);

void handle_player_movement(void);
void handle_player_angle(void);
void apply_player_velocities(void);

void run_player_action(player_action_t action);
void handle_player_shoot(void);
void handle_player_bomb(void);

void damage_player(player_t *player, int amount);

void load_hud(void);
void draw_hud(void);
void draw_player_stats(void);
void draw_inventory(void);

#endif
