/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** ia_caca
*/

#include <math.h>
#include "entity.h"
#include "player.h"

static int move_caca(entity_t *entity, double x, double y)
{
    if (fabs(entity->x - x) < 10 && fabs(entity->y - y) < 10)
        return 1;
    entity->spritesheet.current_step++;
    if (entity->x > x && !(entity->x < x))
        entity->velocity_x -= 5;
    if (entity->x < x && !(entity->x > x))
        entity->velocity_x += 5;
    if (entity->y > y && !(entity->y < y))
        entity->velocity_y -= 5;
    if (entity->y < y && !(entity->y > y))
        entity->velocity_y += 5;
    return 0;
}

static void death_caca(entity_t *entity)
{
    create_clock("death", 0.5f);
    if (entity->x < get_player()->x + 20 && entity->x > get_player()->x -
            20 && entity->y < get_player()->y + 10 &&
            entity->y > get_player()->y - 10 &&
            is_clock_elapsed("death"))
        damage_player(get_player(), 1);
}

void ia_caca(entity_t *entity)
{
    static double player_x = -1;
    static double player_y = -1;

    create_clock("caca_clock", 5.0f);
    if (entity->life <= 0)
        return (on_entity_death(entity));
    if (player_x == -1 && player_y == -1) {
        entity->spritesheet.current_step = 0;
        if (is_clock_elapsed("caca_clock")) {
            player_x = get_player()->x;
            player_y = get_player()->y;
        }
    }
    entity->z = TILE_SIZE / -16.0f;
    death_caca(entity);
    if (player_x != -1 && player_y != -1 &&
            (move_caca(entity, player_x, player_y) == 1)) {
        player_x = -1;
        player_y = -1;
    }
    update_animation(entity->sprite, &entity->spritesheet);
}
